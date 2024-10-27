/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:50:05 by ykoseki           #+#    #+#             */
/*   Updated: 2023/06/03 23:27:01 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
#include <strings.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		tmp_len;

	i = 0;
	j = 0;
	tmp_len = len;
	if (haystack == NULL)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' & len > 0)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] != '\0')
			j++;
		if (j == ft_strlen((const char *)needle) && i + j <= tmp_len)
			return ((char *)haystack + i);
		i++;
		j = 0;
		len--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *str = "libft-test-tokyo";
// 	int	len = strlen(str);
// 	// /* 115 */ ASSERT_EQ_PTR(ft_strnstr(NULL, "1", 0),
// strnstr(NULL, "1", 0));
//     // /* 116 */ ASSERT_EQ_PTR(ft_strnstr(NULL, "fake", 3),
// strnstr(NULL,"fake", 3));
//     // /* 116 */ ASSERT_EQ_PTR(ft_strnstr(NULL, "1", 1),
// ft_strnstr(NULL,"1", 1));
// 	printf("%s",ft_strnstr(NULL, "1", 0));
// 	printf("%c",'\n');
// 	printf("%s",strnstr(NULL, "1", 0));
// 	printf("%c",'\n');
// 	// for (int i = 0; i < len; i++)
// 	// {
// 	// 	printf("%s",ft_strnstr(str, "libft", i));
// 	// 	printf("%c",'\n');
// 	// 	printf("%s",strnstr(str, "libft", i));
// 	// 	printf("%c",'\n');
// 	// 	// ASSERT_EQ_PTR(ft_strnstr(str, "libft-test-tokyo", i),
// strnstr(str,"libft-test-tokyo", i));
// 	// 	// ASSERT_EQ_PTR(ft_strnstr(str, "libft", i),
// strnstr(str, "libft", i));
// 	// 	// ASSERT_EQ_PTR(ft_strnstr(str, "test", i), strnstr(str, "test", i));
// 	// 	// ASSERT_EQ_PTR(ft_strnstr(str, "tokyo", i),
// strnstr(str, "tokyo", i));
// 	// 	// ASSERT_EQ_PTR(ft_strnstr(str, "libft~", i),
// strnstr(str, "libft~",i));
// 	// 	// ASSERT_EQ_PTR(ft_strnstr(str, "z", i), strnstr(str, "z", i));
// 	// }
//     // /* 113 */ ASSERT_EQ_PTR(ft_strnstr("", "hello", 5),
// strnstr("","hello", 5));
//     // /* 114 */ ASSERT_EQ_PTR(ft_strnstr("", "", 0), strnstr("", "", 0));
//     // /* 115 */ ASSERT_EQ_PTR(ft_strnstr(NULL, "1", 0),
// strnstr(NULL, "1",0));
//     // Segmentation Fault
//     // /* 116 */ ASSERT_EQ_PTR(ft_strnstr(NULL, "fake", 3),
// strnstr(NULL,"fake", 3));
//     // /* 116 */ ASSERT_EQ_PTR(ft_strnstr(NULL, "1", 1),
// ft_strnstr(NULL,"1", 1));
// }
