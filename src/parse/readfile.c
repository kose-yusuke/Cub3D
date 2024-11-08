/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:17:18 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/08 13:34:06 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	open_and_allocate_map(t_mgr *mgr, char *map_filepath)
{
	int	fd;

	fd = open(map_filepath, O_RDONLY);
	if (fd < 0)
		exit(ft_error_message_handler("Failed to open map file"));
	mgr->map.grid = (char **)ft_calloc(mgr->map.row + 1, sizeof(char *));
	if (!mgr->map.grid)
	{
		close(fd);
		ft_error_message_handler("Failed to allocate memory for map");
		exit(1);
	}
	return (fd);
}

char	**read_cub_file(t_mgr *mgr, char *map_filepath)
{
	int		fd;
	char	*line;
	int		count_row;

	fd = open_and_allocate_map(mgr, map_filepath);
	count_row = 0;
	line = get_next_line(fd);
	while (line != NULL && count_row < mgr->map.row)
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
		line = get_next_line(fd);
	}
	close(fd);
	return (mgr->map.grid);
}
