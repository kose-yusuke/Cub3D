/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:16:32 by ykoseki           #+#    #+#             */
/*   Updated: 2023/05/28 16:57:28 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*as;

	as = (unsigned char *)s;
	while (n > 0)
	{
		if (*as == (unsigned char)c)
		{
			return (as);
		}
		as++;
		n--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *s = calloc(40, sizeof(char));
// 	// memcpy(s, "libft-test-tokyo", 17);
// 	// memcpy(s + 20, "acdfg", 5);
// 	memcpy(s, "/|\x12\xff\x09\x42\2002\42|\\", 30);
// 	// memcpy(s + 20, "acdfg", 5);
// 	// printf("%s",ft_memchr(s, '', 30));
// 	// printf("%s",memchr(s, 'f', 30));
// 	// char *src = "/|\x12\xff\x09\x42\2002\42|\\";
// 	printf("%s",ft_memchr(s, '\200', 10));
// 	printf("%c",'\n');
// 	printf("%s",memchr(s, '\200', 30));
// }