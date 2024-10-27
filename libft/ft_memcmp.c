/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:44:42 by ykoseki           #+#    #+#             */
/*   Updated: 2023/05/28 16:58:07 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include <strings.h>
// #include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}

// int	main(void)
// {
// 	// int	len = 30;
// 	// char *str = calloc(30, sizeof(char));
// 	// char *cmp = calloc(30, sizeof(char));
// 	// memcpy(str, "libft-test-tokyo", 16);
// 	// memcpy(cmp, "libft-test-tokyo", 16);
// 	// memcpy(str + 20, "acdfg", 5);
// 	// memcpy(cmp + 20, "acdfg", 5);
// 	/* 1 ~ 31 */
// 	// for (int i = 0; i <= len; i++)
// 	// {
// 	// 	printf("%d",ft_memcmp(str, cmp, i));
// 	// 	printf("adfghjk");
// 	// 	printf("%d",memcmp(str, cmp, i));
// 	// }
// 	char *s1 = "\xff\xaa\xde\xffMACOSX\xff";
// 	char *s2 = "\xff\xaa\xde\x02";
// 	size_t size = 8;
// 	// int i1 = simple_memcmp(s1, s2, size);
// 	// int i2 = ft_memcmp(s1, s2, size);
// 	for (int i = 0; i <= size; i++)
// 	{
// 		printf("%d",ft_memcmp(s1, s2, i));
// 		printf("%c",'\n');
// 		printf("%d",memcmp(s1, s2, i));
// 		printf("%c",'\n');
// 	}
// 	// /* 32 ~ 93 */
// 	// for (int i = 0; i <= len; i++)
// 	// {
// 	// 	cmp = strndup(str, i);
// 	// 	ASSERT_EQ_I(ft_memcmp(str, cmp, i), memcmp(str, cmp, i));
// 	// 	ASSERT_EQ_I(ft_memcmp(str, cmp, len), memcmp(str, cmp, len));
// 	// 	free(cmp);
// 	// }
// 	// char *cmp2 = calloc(30, sizeof(char));
// 	// strlcpy(cmp2, "libft", sizeof(char));
// 	// cmp2[5] = CHAR_MIN;
// 	// /* 94 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
// 	// cmp2[5] = -42;
// 	// /* 95 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
// 	// cmp2[5] = 0;
// 	// /* 96 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
// 	// cmp2[5] = 42;
// 	// /* 97 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
// 	// cmp2[5] = CHAR_MAX;
// 	// /* 98 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));

// 	// strlcpy(cmp2, "libft-test-tokyo", sizeof(char));
// 	// strlcpy(cmp2 + 20, "acdfg", sizeof(char));
// 	// cmp2[29] = CHAR_MIN;
// 	// /* 99 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
// 	// cmp2[29] = -42;
// 	// /* 100 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
// 	// cmp2[29] = 0;
// 	// /* 101 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
// 	// cmp2[29] = 42;
// 	// /* 102 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
// 	// cmp2[29] = CHAR_MAX;
// 	// /* 103 */ ASSERT_EQ_I(ft_memcmp(str, cmp2, len), memcmp(str, cmp2, len));
// 	// return (0);
// }