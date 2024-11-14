#include "cub3d.h"

char	**allocate_map(int rows, int cols)
{
	char	**map;
	int		i;

	if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS)
		error_exit("Invalid map size");
	map = xmalloc(sizeof(char *) * rows);
	i = 0;
	while (i < rows)
	{
		map[i] = xmalloc(sizeof(char) * (cols + 1)); // +`\0`
		ft_memset(map[i], ' ', cols);
		map[i][cols] = '\0';
		i++;
	}
	return (map);
}

void	copy_grid_line(char *grid_row, char *line)
{
	if (!grid_row || !line)
		return ;
	while (*grid_row && *line && *line != '\n')
	{
		*grid_row = *line; // '\n' '\0'はコピーしたくない
		grid_row++;
		line++;
	}
}

bool	parse_map_figure(t_map *map, int fd)
{
	char	*line;
	int		i;

	line = skip_blank_lines(fd);
	i = 0;
	while (line && i < map->row)
	{
		copy_grid_line(map->grid[i], line);
		xfree(line);
		line = get_next_line(fd);
		i++;
	}
	while (line)
	{
		xfree(line);
		line = get_next_line(fd);
	}
	return (i == map->row);
}

// TODO: debug print -> remove
bool	parse_file(t_mgr *mgr, char *map_filepath)
{
	const int	fd = xopen(map_filepath);

	if (!parse_map_data(mgr->textures, fd) || !parse_map_figure(&mgr->map, fd))
	{
		xclose(fd);
		return (false);
	}
	xclose(fd);
	return (true);
}

void	print_color(char *place, t_rgb *rgb)
{
	printf("%s : %d,%d,%d\n", place, rgb->red, rgb->green, rgb->blue);
}

void	print_data(t_textures *textures)
{
	printf("Data\n");
	printf("-----------------\n");
	printf("NO : %s\n", textures->north_texture_path);
	printf("SO : %s\n", textures->south_texture_path);
	printf("WE : %s\n", textures->west_texture_path);
	printf("EA : %s\n", textures->east_texture_path);
	print_color("F ", &textures->f_rgb);
	print_color("C ", &textures->c_rgb);
}

void	print_map(t_map *map)
{
	printf("\nMap (col %d, row %d)\n", map->column, map->row);
	printf("-----------------\n");
	for (int i = 0; i < map->row; i++)
		printf("%s\n", map->grid[i]);
}

void	init_mgr(t_mgr *mgr, char *map_filepath)
{
	// row & column の大きさは、validate_map()で取得済み
	mgr->textures = xmalloc(sizeof(t_textures));
	ft_bzero(mgr->textures, sizeof(t_textures)); // 初期化
	mgr->map.grid = allocate_map(mgr->map.row, mgr->map.column);
	if (!parse_file(mgr, map_filepath))
		error_exit("Invalid map");
	print_data(mgr->textures); // TODO: remove
	print_map(&mgr->map); // TODO: remove
}
