/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:36:11 by sakitaha          #+#    #+#             */
/*   Updated: 2024/11/15 17:36:36 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_data_content(char *line, t_check_list *check_list)
{
	char	*id;
	char	*setting;

	skip_space(&line);
	if (*line == '\n' || *line == '\0')
		return ;
	id = line;
	skip_nonspace(&line);
	skip_space(&line);
	if (*line == '\n' || *line == '\0')
	{
		check_list->invalid = true;
		return ;
	}
	setting = line;
	validate_setting(id, setting, check_list);
}

static bool	is_check_list_satisfied(t_check_list *check_list)
{
	if (check_list->invalid)
		return (false);
	if (check_list->north && check_list->south && check_list->west
		&& check_list->east && check_list->floor && check_list->ceiling)
		return (true);
	return (false);
}

static bool	validate_map_data(int fd)
{
	t_check_list	check_list;
	char			*line;

	ft_bzero(&check_list, sizeof(t_check_list));
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			return (false);
		check_data_content(line, &check_list);
		free(line);
		if (check_list.invalid)
			return (false);
		if (is_check_list_satisfied(&check_list))
			return (true);
	}
}

bool	validate_map(t_map *map, const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit(strerror(errno));
	ft_bzero(map, sizeof(t_map));
	if (!validate_map_data(fd) || !validate_map_figure(map, fd))
	{
		close(fd);
		error_exit("Invalid map");
	}
	close(fd);
	return (true);
}
