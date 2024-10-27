/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:41:01 by ykoseki           #+#    #+#             */
/*   Updated: 2023/05/28 14:41:58 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, (char *)s1, ft_strlen((char *)s1) + 1);
	ft_strlcpy(tmp + ft_strlen((char *)s1), (char *)s2, ft_strlen((char *)s2)
		+ 1);
	return (tmp);
}

// int	main(void)
// {
// 	printf("%s",ft_strjoin("hello", "world"));
// 	printf("%c",'\n');
// 	printf("%s","helloworld");
// 	// /* 1 */ ASSERT_EQ_STR(ft_strjoin("hello", "world"), "helloworld");
// 	// /* 2 */ ASSERT_EQ_STR(ft_strjoin("", "world"), "world");
// 	// /* 3 */ ASSERT_EQ_STR(ft_strjoin("hello", ""), "hello");
// 	// /* 4 */ ASSERT_EQ_STR(ft_strjoin("", ""), "");
// }