/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:35:31 by sakitaha          #+#    #+#             */
/*   Updated: 2024/11/15 17:35:32 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	skip_space(char **tmp)
{
	if (!tmp || !*tmp)
		return ;
	while (**tmp == ' ')
		(*tmp)++;
}

void	skip_nonspace(char **tmp)
{
	if (!tmp || !*tmp)
		return ;
	while (**tmp && **tmp != ' ')
		(*tmp)++;
}

bool	is_blank_line(char *line)
{
	skip_space(&line);
	return (*line == '\0' || *line == '\n');
}

char	*skip_blank_lines(int fd)
{
	char	*line;

	line = NULL;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		if (!is_blank_line(line))
			return (line);
		free(line);
	}
}
