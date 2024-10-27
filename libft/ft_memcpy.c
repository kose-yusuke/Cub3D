/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 01:55:17 by ykoseki           #+#    #+#             */
/*   Updated: 2023/06/23 21:28:54 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst_byte;
	const char	*src_byte;

	if (!dst)
		return (NULL);
	dst_byte = (char *)dst;
	src_byte = (const char *)src;
	i = 0;
	while (n > i)
	{
		dst_byte[i] = src_byte[i];
		i++;
	}
	return (dst);
}

// int main(void)
// {
// 	char *src = malloc(100);
// 	char *dst = malloc(100);
// 	src = NULL;
// 	printf("%p",memcpy(dst, NULL, 0));

// 	printf("%p",ft_memcpy(dst, NULL, 0));
// 	ft_memcpy(dst, src, 0);
//     return 0;
// }