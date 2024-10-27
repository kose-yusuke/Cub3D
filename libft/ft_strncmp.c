/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 02:47:43 by ykoseki           #+#    #+#             */
/*   Updated: 2023/06/03 23:17:02 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (s1 == NULL || s2 == NULL || n == '\0')
		return (0);
	if (n == 0)
		return (0);
	while (*s1 != '\0' && n - 1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// int	main(void)
// {
// 	char *str = "abcdef";
// 	char *cmp = "abcdefghijklmnop";
// 	int	len = strlen(str);
// 	// for (int i = 0; i <= len; i++)
// 	// {
// 		// cmp = strndup(str, i);
// 		// printf("%s",cmp);
// 		// printf("aaaaa");
// 		// printf("%d",ft_strncmp(str, cmp, i));
// 		// printf("aaaaa");
// 		// printf("%d",strncmp(str, cmp, i));
// 		// printf("aaaaa");
// 		printf("%d",ft_strncmp(str, cmp, 6));
// 		printf("aaaaa");
// 		printf("%d",strncmp(str, cmp, 6));
// 		printf("aaaaa");
// 	// 	free(cmp);
// 	// }
// 	return (0);
// }