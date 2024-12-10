/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:35:48 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/10 15:42:01 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	trim_trailing_space(char *str)
{
	char	*end;

	if (!str || !*str)
		return ;
	end = str + ft_strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\n'))
	{
		*end = '\0';
		end--;
	}
}

char	*prepare_trimmed_path(char *path)
{
	char	*path_copy;

	path_copy = ft_strdup(path);
	if (!path_copy)
		return (NULL);
	trim_trailing_space(path_copy);
	return (path_copy);
}

bool	is_valid_extension(const char *path, const char *ext)
{
	const size_t	path_len = ft_strlen(path);
	const size_t	ext_len = ft_strlen(ext);

	if (!path || !ext || path_len <= ext_len)
		return (false);
	return (ft_strncmp(&path[path_len - ext_len], ext, ext_len) == 0);
}

bool	is_valid_path(const char *path_copy)
{
	int	fd;

	fd = open(path_copy, O_RDONLY);
	if (fd == -1)
	{
		return (false);
	}
	close(fd);
	return (true);
}
