/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 04:19:25 by ykoseki           #+#    #+#             */
/*   Updated: 2023/06/03 23:12:50 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ans;
	int		i;
	size_t	mem;

	i = 0;
	mem = count * size;
	if (size != 0 && count >= SIZE_MAX / size)
		return (NULL);
	ans = (char *)malloc(sizeof(char) * (mem));
	if (!ans)
		return (NULL);
	while (mem > 0)
	{
		ans[i] = 0;
		i++;
		mem--;
	}
	return (ans);
}

// void	check_calloc(size_t cnt, size_t size)
// {
// 	void	*actual = ft_calloc(cnt, size);
// 	void	*expected = calloc(cnt, size);
// 	printf("%s", actual);
// 	printf("%s", expected);

// 	// ASSERT_EQ_MALLOC_SIZE(actual, expected);
// 	// ASSERT_EQ_MEM(actual, expected, cnt * size);
// }

// int	main(void)
// {
// 	/* 1,2 */ check_calloc(0, 0);
// 	// /* 3,4 */ check_calloc(1, 0);
// 	// /* 5,6 */ check_calloc(0, 1);
// 	// /* 7,8 */ check_calloc(1, 1);
// 	// /* 9,10 */ check_calloc(42, 1);
// 	// /* 11,12 */ check_calloc(1, 42);
// 	// /* 13,14 */ check_calloc(42, 42);
// 	/* 15,16 overflow */
// 	// check_calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10);
// 	// /* 17,18 too big 1*/ check_calloc(LONG_MAX, 1);
// 	// /* 19,20 too big 2*/ check_calloc(ULONG_MAX, 1);
// 	// /* 21,22 too big 3*/ check_calloc(SIZE_MAX, 1);
// 	// /* 23,24 very big 1*/ check_calloc(INT_MAX, 1);
// 	// /* 25,26 very big 2*/ check_calloc(UINT_MAX, 1);
// 	return (0);
// }