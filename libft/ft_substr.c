/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:34:20 by ykoseki           #+#    #+#             */
/*   Updated: 2023/06/03 22:53:51 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	unsigned int	slen;
	int				i;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen((char *)s);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (start < slen && len > 0 && slen > 0)
	{
		tmp[i] = *(s + start);
		i++;
		s++;
		len--;
		slen--;
	}
	tmp[i] = '\0';
	return (tmp);
}

// int	main(void)
// {
// 	// char *s = "libft-test-tokyo";
// 	char *s = "i just want this part #############";
// 	printf("%s",ft_substr(s, 5, 10));
// 	printf("%c",'\n');
// 	printf("%s",s);
// 	printf("%c",'\n');
// 	// /* 1 */ ASSERT_EQ_STR(ft_substr(s, 0, 100), s);
// 	// /* 3 */ ASSERT_EQ_STR(ft_substr(s, 5, 100), s + 5);
// 	// /* 3 */ ASSERT_EQ_STR(ft_substr(s, 10, 100), s + 10);
// 	// /* 4 */ ASSERT_EQ_STR(ft_substr(s, 15, 100), s + 15);
// 	// /* 5 */ ASSERT_EQ_STR(ft_substr(s, 20, 100), "");
// 	// /* 6 */ ASSERT_EQ_STR(ft_substr(s, 0, 5), "libft");
// 	// /* 7 */ ASSERT_EQ_STR(ft_substr(s, 5, 5), "-test");
// 	// /* 8 */ ASSERT_EQ_STR(ft_substr(s, 10, 5), "-toky");
// 	// /* 9 */ ASSERT_EQ_STR(ft_substr(s, 15, 5), "o");
// 	// /* 10 */ ASSERT_EQ_STR(ft_substr(s, 20, 5), "");
// 	// /* 11 */ ASSERT_EQ_STR(ft_substr(s, 0, 0), "");
// 	// /* 12 */ ASSERT_EQ_STR(ft_substr(s, 5, 0), "");
// 	// /* 13 */ ASSERT_EQ_STR(ft_substr(s, 10, 0), "");
// 	// /* 14 */ ASSERT_EQ_STR(ft_substr(s, 15, 0), "");
// 	// /* 15 */ ASSERT_EQ_STR(ft_substr(s, 20, 0), "");
// }
