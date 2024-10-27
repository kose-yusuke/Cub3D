/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:00:24 by ykoseki           #+#    #+#             */
/*   Updated: 2023/05/28 15:36:59 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	int		len;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!tmp)
		return (NULL);
	while (len > 0)
	{
		tmp[i] = f(i, *s);
		len--;
		s++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

// #include <ctype.h>
// #include <stdio.h>
// static int (*f)(int) = NULL;
// static char F(unsigned int i, char c) { (void)i; return (f(c)); };
// static int plus_one(int c) { return (c + 1); }

// int main(void)
// {
//     f = toupper;
// 	printf("%s",ft_strmapi("abcde", F));

//     // /* 1 */ ASSERT_EQ_STR(ft_strmapi("abcde", F), "ABCDE");
//     // /* 2 */ ASSERT_EQ_STR(ft_strmapi("Hello World!", F), "HELLO WORLD!");
//     // /* 3 */ ASSERT_EQ_STR(ft_strmapi("12345", F), "12345");
//     // f = tolower;
//     // /* 4 */ ASSERT_EQ_STR(ft_strmapi("ABCDE", F), "abcde");
//     // /* 5 */ ASSERT_EQ_STR(ft_strmapi("Hello World!", F), "hello world!");
//     // /* 6 */ ASSERT_EQ_STR(ft_strmapi("12345", F), "12345");
//     // f = plus_one;
//     // /* 7 */ ASSERT_EQ_STR(ft_strmapi("ABCDE", F), "BCDEF");
//     // /* 8 */ ASSERT_EQ_STR(ft_strmapi("Hello World!", F), "Ifmmp!Xpsme\"");
//     // /* 9 */ ASSERT_EQ_STR(ft_strmapi("12345", F), "23456");
// }