/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:06:07 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/08 13:51:19 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	absolute_value(double value)
{
	if (value < 0)
		return (-value);
	return (value);
}

size_t	ft_strlen_until_newline(const char *str)
{
	int	a;

	a = 0;
	while (*(str + a) != '\0' && *(str + a) != '\n')
		a++;
	return (a);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strndup(char *src, long len)
{
	char	*p;

	if (src == NULL)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	ft_strncpy(p, src, len);
	p[len] = '\0';
	return (p);
}

void	print_grid(t_mgr *mgr)
{
	int	i;

	i = 0;
	while (mgr->map.grid[i] != NULL && i < mgr->map.row)
	{
		printf("%s", mgr->map.grid[i]);
		i++;
	}
	printf("%s", "\n");
}
