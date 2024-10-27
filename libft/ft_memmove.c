/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 02:05:46 by ykoseki           #+#    #+#             */
/*   Updated: 2023/07/08 02:59:41 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

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
