/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:06:59 by ykoseki           #+#    #+#             */
/*   Updated: 2024/12/07 15:10:37 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			last = s;
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)last);
}
// int main()
// {
// 	char *s = "libft-test-tokyo";

// 	/* 17 */ ASSERT_EQ_STR(ft_strrchr(s, '\0'), strrchr(s, '\0'));
// 	/* 18 */ ASSERT_EQ_STR(ft_strrchr(s, 'l' + 256), strrchr(s, 'l' + 256));
// 	/* 19 */ ASSERT_EQ_STR(ft_strrchr(s, 'i' + 256), strrchr(s, 'i' + 256));
// 	/* 20 */ ASSERT_EQ_STR(ft_strrchr(s, 'l' - 256), strrchr(s, 'l' - 256));
// 	/* 21 */ ASSERT_EQ_STR(ft_strrchr(s, 'i' - 256), strrchr(s, 'i' - 256));
// }
