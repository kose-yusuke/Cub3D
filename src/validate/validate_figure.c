/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_figure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:33:04 by sakitaha          #+#    #+#             */
/*   Updated: 2024/11/15 17:35:04 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_map_input(char *line)
{
	while (*line)
	{
		if (!is_map_char(*line) && *line != '\n')
			return (false);
		line++;
	}
	return (true);
}

static void	update_flags(bool *is_valid_map, bool *in_map, char *line)
{
	if (*in_map)
	{
		if (is_blank_line(line))
			*in_map = false;
		else if (!is_valid_map_input(line))
			*is_valid_map = false;
		return ;
	}
	if (!is_blank_line(line))
		*is_valid_map = false;
}

static void	update_map_size(t_map *map, char *line, bool *is_valid_map)
{
	size_t	line_len;

	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line_len--;
	if (line_len > INT_MAX)
	{
		*is_valid_map = false;
		return ;
	}
	if (map->column < (int)line_len)
		map->column = (int)line_len;
	map->row++;
}

bool	validate_map_figure(t_map *map, int fd)
{
	char	*line;
	bool	is_valid_map;
	bool	in_map;

	line = skip_blank_lines(fd);
	is_valid_map = true;
	in_map = true;
	while (line)
	{
		update_flags(&is_valid_map, &in_map, line);
		if (is_valid_map && in_map)
		{
			update_map_size(map, line, &is_valid_map);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (map->row == 0 || map->column == 0)
		is_valid_map = false;
	return (is_valid_map);
}
