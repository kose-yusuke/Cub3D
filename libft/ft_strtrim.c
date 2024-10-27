/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:48:31 by ykoseki           #+#    #+#             */
/*   Updated: 2023/05/28 16:59:19 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_set(char *s1, char *set)
{
	while (*set != '\0')
	{
		if (*s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	char	*back_trim;
	char	*ans;
	int		total_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 != '\0' && is_set((char *)s1, (char *)set))
		s1++;
	total_len = ft_strlen((char *)s1);
	back_trim = (char *)s1 + total_len - 1;
	while (*s1 != '\0' && is_set(back_trim, (char *)set))
	{
		back_trim--;
		total_len--;
	}
	tmp = ft_calloc(total_len + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	ans = tmp;
	while (total_len-- > 0)
		*tmp++ = *s1++;
	*tmp = '\0';
	return (ans);
}

// int	main(void)
// {
// 	// printf("%s", ft_strtrim("hello world", "world"));
// 	printf("%s",
// ft_strtrim("   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me
// !\n   \n \n \t\t\n  "," \n\t"));
// 	// /* 1 */ ASSERT_EQ_STR(ft_strtrim("hello world", "world"), "hello ");
// 	// /* 2 */ ASSERT_EQ_STR(ft_strtrim("hello world", "hello"), " world");
// 	// /* 3 */ ASSERT_EQ_STR(ft_strtrim("hello world", ""), "hello world");
// 	// /* 4 */ ASSERT_EQ_STR(ft_strtrim("", ""), "");
// 	// /* 5 */ ASSERT_EQ_STR(ft_strtrim("    hello world     ", " "),
// 			// "hello world");
// 	//
// // /* 6 */ ASSERT_EQ_STR(
// 	// ft_strtrim(" \n\t\r    hello \n\t\r world     \r\t\n\t \r\n",
// 				// " \n\t\r"), "hello \n\t\r world");
// 	// /* 7 */ ASSERT_EQ_STR(ft_strtrim("hello world",
// 				// "abcdefghijklmnopqrstuvwxyz"), " ");
// }