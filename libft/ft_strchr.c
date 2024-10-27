/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:38:54 by ykoseki           #+#    #+#             */
/*   Updated: 2023/05/28 17:36:40 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		while (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

// int	main(void)
// {
// 	// char *s = "libft-test-tokyo";
// 	char *s = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
// 	// printf("%s",ft_strchr(s, 'l'));
// 	// printf("%c",'\n');
// 	// printf("%s",strchr(s, 'l'));
// 	printf("%s",ft_strchr(s, '\0'));
// 	// printf("%c",'\n');
// 	// printf("%s",strchr(s, '\0'));
// // 	// /* 1 */ printf(ft_strchr(s, 'l'), strchr(s, 'l'));
// // 	// /* 2 */ printf(ft_strchr(s, 'i'), strchr(s, 'i'));
// // 	// /* 3 */ printf(ft_strchr(s, 'b'), strchr(s, 'b'));
// // 	// /* 4 */ printf(ft_strchr(s, 'f'), strchr(s, 'f'));
// // 	// /* 5 */ printf(ft_strchr(s, 't'), strchr(s, 't'));
// // 	// /* 6 */ printf(ft_strchr(s, '-'), strchr(s, '-'));
// // 	// /* 7 */ printf(ft_strchr(s, 't'), strchr(s, 't'));
// // 	// /* 8 */ printf(ft_strchr(s, 'e'), strchr(s, 'e'));
// // 	// /* 9 */ printf(ft_strchr(s, 's'), strchr(s, 's'));
// // 	// /* 10 */ printf(ft_strchr(s, 't'), strchr(s, 't'));
// // 	// /* 11 */ printf(ft_strchr(s, '-'), strchr(s, '-'));
// // 	// /* 12 */ printf(ft_strchr(s, 't'), strchr(s, 't'));
// // 	// /* 13 */ printf(ft_strchr(s, 'o'), strchr(s, 'o'));
// // 	// /* 14 */ printf(ft_strchr(s, 'k'), strchr(s, 'k'));
// // 	// /* 15 */ printf(ft_strchr(s, 'y'), strchr(s, 'y'));
// // 	// /* 16 */ printf(ft_strchr(s, 'o'), strchr(s, 'o'));
// // 	// /* 17 */ printf(ft_strchr(s, '\0'), strchr(s, '\0'));
// // 	// /* 18 */ printf(ft_strchr(s, 'l' + 256), strchr(s, 'l' + 256));
// // 	// /* 19 */ printf(ft_strchr(s, 'i' + 256), strchr(s, 'i' + 256));
// // 	// /* 20 */ printf(ft_strchr(s, 'l' - 256), strchr(s, 'l' - 256));
// // 	// /* 21 */ printf(ft_strchr(s, 'i' - 256), strchr(s, 'i' - 256));
// // 	// /* 22 */ printf(ft_strchr(s, 'z'), strchr(s, 'z'));
// // 	// /* 23 */ printf(ft_strchr(s, '~'), strchr(s, '~'));
// 	return (0);
// }