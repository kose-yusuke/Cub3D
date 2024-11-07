/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:17:18 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/08 00:06:52 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_xpmfile(t_mgr *mgr)
{
	mgr->wall_img[NORTH_WALL].img = mlx_xpm_file_to_image(mgr->mlx,
			mgr->textures->north_texture_path, &mgr->wall_img[NORTH_WALL].width,
			&mgr->wall_img[NORTH_WALL].height);
	mgr->wall_img[NORTH_WALL].addr = mlx_get_data_addr(mgr->wall_img[NORTH_WALL].img,
			&mgr->wall_img[NORTH_WALL].bits_per_pixel,
			&mgr->wall_img[NORTH_WALL].line_length,
			&mgr->wall_img[NORTH_WALL].endian);
	mgr->wall_img[SOUTH_WALL].img = mlx_xpm_file_to_image(mgr->mlx,
			mgr->textures->south_texture_path, &mgr->wall_img[SOUTH_WALL].width,
			&mgr->wall_img[SOUTH_WALL].height);
	mgr->wall_img[SOUTH_WALL].addr = mlx_get_data_addr(mgr->wall_img[SOUTH_WALL].img,
			&mgr->wall_img[SOUTH_WALL].bits_per_pixel,
			&mgr->wall_img[SOUTH_WALL].line_length,
			&mgr->wall_img[SOUTH_WALL].endian);
	mgr->wall_img[WEST_WALL].img = mlx_xpm_file_to_image(mgr->mlx,
			mgr->textures->west_texture_path, &mgr->wall_img[WEST_WALL].width,
			&mgr->wall_img[WEST_WALL].height);
	mgr->wall_img[WEST_WALL].addr = mlx_get_data_addr(mgr->wall_img[WEST_WALL].img,
			&mgr->wall_img[WEST_WALL].bits_per_pixel,
			&mgr->wall_img[WEST_WALL].line_length,
			&mgr->wall_img[WEST_WALL].endian);
	mgr->wall_img[EAST_WALL].img = mlx_xpm_file_to_image(mgr->mlx,
			mgr->textures->east_texture_path, &mgr->wall_img[EAST_WALL].width,
			&mgr->wall_img[EAST_WALL].height);
	mgr->wall_img[EAST_WALL].addr = mlx_get_data_addr(mgr->wall_img[EAST_WALL].img,
			&mgr->wall_img[EAST_WALL].bits_per_pixel,
			&mgr->wall_img[EAST_WALL].line_length,
			&mgr->wall_img[EAST_WALL].endian);
	// mlx_put_image_to_window(mgr->mlx, mgr->win, mgr->wall_img[EAST_WALL].img,0, 0);
}

int	count_rows(t_mgr *mgr, char *map_filepath)
{
	int		fd;
	int		count_row;
	char	*row;

	fd = open(map_filepath, O_RDONLY);
	if (fd < 0)
		return (0);
	count_row = 0;
	while (true)
	{
		row = get_next_line(fd);
		if (!row)
			break ;
		if (ft_strncmp(row, "1", 1) == 0)
			count_row++;
		free(row);
		row = NULL;
	}
	close(fd);
	return (count_row);
}

int	count_columns(t_mgr *mgr)
{
	return (ft_strlen(mgr->map.grid[0]));
}

void	parse_rgb(char *line, t_rgb *rgb)
{
	char	*start;
	char	*end;

	start = line;
	end = ft_strchr(start, ',');
	if (end == NULL)
		exit(ft_error_message_handler("Invalid RGB format"));
	*end = '\0';
	rgb->red = ft_atoi(start);
	start = end + 1;
	end = ft_strchr(start, ',');
	if (end == NULL)
		exit(ft_error_message_handler("Invalid RGB format"));
	*end = '\0';
	rgb->green = ft_atoi(start);
	start = end + 1;
	end = ft_strchr(start, '\n');
	if (end == NULL)
		exit(ft_error_message_handler("Invalid RGB format"));
	*end = '\0';
	rgb->blue = ft_atoi(start);
}

//最低限
void	parse_texture_line(char *line, t_mgr *mgr, int count_row)
{
	int	len;

	len = ft_strlen_until_newline(line);
	if (ft_strncmp(line, "NO ", 3) == 0)
		mgr->textures->north_texture_path = ft_strndup(line + 3, len - 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		mgr->textures->south_texture_path = ft_strndup(line + 3, len - 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		mgr->textures->west_texture_path = ft_strndup(line + 3, len - 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		mgr->textures->east_texture_path = ft_strndup(line + 3, len - 3);
	else if (ft_strncmp(line, "F ", 2) == 0)
	{
		parse_rgb(line + 2, &mgr->textures->f_rgb);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_rgb(line + 2, &mgr->textures->c_rgb);
	return ;
}

char	**read_cub_file(t_mgr *mgr, char *map_filepath)
{
	int		fd;
	char	*line;
	int		count_row;

	fd = open(map_filepath, O_RDONLY);
	count_row = 0;
	if (fd < 0)
		exit(ft_error_message_handler("Failed to open map file"));
	mgr->map.grid = (char **)ft_calloc(mgr->map.row + 1, sizeof(char *));
	if (!mgr->map.grid)
		return (NULL);
	while ((line = get_next_line(fd)) != NULL && count_row < mgr->map.row)
	{
		parse_texture_line(line, mgr, count_row);
		if (ft_strncmp(line, "1", 1) == 0)
		{
			mgr->map.grid[count_row] = ft_strdup(line);
			if (!mgr->map.grid[count_row])
			{
				close(fd);
				return (NULL);
			}
			count_row++;
		}
		free(line);
		line = NULL;
	}
	close(fd);
	return (mgr->map.grid);
}
