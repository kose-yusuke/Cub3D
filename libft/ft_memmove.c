/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 02:05:46 by ykoseki           #+#    #+#             */
/*   Updated: 2024/12/07 15:09:29 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_byte;
	char	*src_byte;

	if (!dst || !src)
		return (NULL);
	dst_byte = (char *)dst;
	src_byte = (char *)src;
	i = 0;
	while (dst_byte < src_byte && len > 0)
	{
		dst_byte[i] = src_byte[i];
		i++;
		len--;
	}
	while (dst_byte >= src_byte && len > 0)
	{
		dst_byte[len - 1] = src_byte[len - 1];
		len--;
	}
	return (dst);
}
