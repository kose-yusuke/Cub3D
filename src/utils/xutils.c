/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:27:01 by sakitaha          #+#    #+#             */
/*   Updated: 2024/11/15 17:27:02 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	xfree(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	*xmalloc(size_t size)
{
	void	*buffer;

	if (size == 0)
		return (NULL);
	buffer = malloc(size);
	if (!buffer)
		error_exit(strerror(errno));
	return (buffer);
}

int	xopen(char *map_filepath)
{
	int	fd;

	fd = open(map_filepath, O_RDONLY);
	if (fd == -1)
		error_exit(strerror(errno));
	return (fd);
}

int	xclose(int fildes)
{
	if (close(fildes) == -1)
	{
		perror("xclose error");
		return (-1);
	}
	return (0);
}
