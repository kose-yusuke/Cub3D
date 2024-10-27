/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 02:42:11 by ykoseki           #+#    #+#             */
/*   Updated: 2023/06/03 23:16:17 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	max_copy;
	size_t	destnum;

	if (dest == NULL)
		return (size + ft_strlen(src));
	destnum = ft_strlen(dest);
	i = 0;
	max_copy = size - destnum - 1;
	if (size <= destnum)
		return (size + ft_strlen(src));
	while (i < max_copy)
	{
		if (src[i] == '\0')
			break ;
		dest[destnum + i] = src[i];
		i++;
	}
	dest[i + destnum] = '\0';
	return (destnum + ft_strlen(src));
}

// int main(void)
// {
// 	char *src = calloc(100, sizeof(char));
// 	// for (int i = 0; i < 67; i++)
// 	// {
// 	// 	src[i] = i + 1;
// 	// }
// 	src = "aysahdas";
// 	// printf("%lu",strlcat(NULL, src, 0));
// 	printf("%lu",ft_strlcat(NULL, src, 0));
// }