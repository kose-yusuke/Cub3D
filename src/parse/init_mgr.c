/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mgr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:32:35 by sakitaha          #+#    #+#             */
/*   Updated: 2024/11/15 17:32:50 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**allocate_map(int rows, int cols)
{
	char	**map;
	int		i;

	if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS)
		error_exit("Invalid map size");
	map = xmalloc(sizeof(char *) * rows);
	i = 0;
	while (i < rows)
	{
		map[i] = xmalloc(sizeof(char) * (cols + 1));
		ft_memset(map[i], ' ', cols);
		map[i][cols] = '\0';
		i++;
	}
	return (map);
}

static void	copy_grid_line(char *grid_row, char *line)
{
	if (!grid_row || !line)
		return ;
	while (*grid_row && *line && *line != '\n')
	{
		*grid_row = *line;
		grid_row++;
		line++;
	}
}

static bool	parse_map_figure(t_map *map, int fd)
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

static bool	parse_file(t_mgr *mgr, char *map_filepath)
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

void	init_mgr(t_mgr *mgr, char *map_filepath)
{
	mgr->textures = xmalloc(sizeof(t_textures));
	ft_bzero(mgr->textures, sizeof(t_textures));
	mgr->map.grid = allocate_map(mgr->map.row, mgr->map.column);
	if (!parse_file(mgr, map_filepath))
		error_exit("Invalid map");
	if (!check_map_validity(mgr))
		exit(EXIT_FAILURE);
}
