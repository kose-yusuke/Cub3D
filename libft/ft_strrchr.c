/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:06:59 by ykoseki           #+#    #+#             */
/*   Updated: 2023/05/28 13:58:25 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

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
