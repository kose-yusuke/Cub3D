/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:53:07 by ykoseki           #+#    #+#             */
/*   Updated: 2023/06/03 22:50:50 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_number(char *s, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c)
			cnt++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (cnt);
	}
	return (cnt);
}

static int	ft_strlen_alpha(char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != charset)
		i++;
	return (i);
}

static char	*each_phrase(char *str, char charset)
{
	int		size2;
	int		i;
	char	*ans;

	if (str == NULL)
		return (NULL);
	i = 0;
	size2 = ft_strlen_alpha(str, charset);
	ans = (char *)malloc(sizeof(char) * (size2 + 1));
	if (!ans)
		return (NULL);
	while (str[i] != charset && str[i] != '\0')
	{
		ans[i] = str[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

static char	**ft_all_free(char **output)
{
	size_t	i;

	i = 0;
	while (output[i] != NULL)
	{
		free(output[i]);
		i++;
	}
	free(output);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	output = ft_calloc(ft_split_number((char *)s, c) + 1, sizeof(char *));
	if (!output)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			output[i] = each_phrase((char *)s, c);
			if (output[i] == NULL)
				return (ft_all_free(output));
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	return (output);
}

// #include <stdio.h>

// int    main(void)
// {
//     char    *str;
//     char    charset;
//     char    **ans;

//     // str = "hello,world,42,tokyo";
// 	str = "\0aa\0bbb";
//     charset = '\0';
//     ans = ft_split(str, charset);
//     // printf("0: %s\n", ans[0]);
// 	// printf("1: %s\n", ans[1]);
// 	// printf("0: %s\n", ans[2]);
// 	// printf("1: %s\n", ans[3]);
// 	// printf("1: %s\n", ans[4]);
//     // printf("1: %s\n", ans[1]);
//     // printf("2: %s\n", ans[2]);
//     // printf("3: %s\n", ans[3]);
//     // printf("4: %s\n", ans[4]);
// 	// printf("5: %s\n", ans[5]);
// }

// //strに幾つの文字列が格納されているか出す関数
// int	ft_big_size(char *str, char charset)
// {
// 	int	count;
// 	int	i;
// 	int	flag;

// 	count = 0;
// 	i = 0;
// 	flag = 0;
// 	while (str[i] != '\0')
// 	{
// 		while (defnum(str[i], charset) == 1 && str[i] != '\0')
// 		{
// 			i++;
// 			flag = 1;
// 		}
// 		if (flag == 1)
// 			count++;
// 		while (defnum(str[i], charset) == 0 && str[i] != '\0')
// 			i++;
// 	}
// 	return (count);
// }

// char **ft_split(char const *s, char c)
// {
// 	char	**ans;
// 	int		i;
// 	int		j;
// 	int		size1;

// 	i = 0;
// 	j = 0;
// 	size1 = ft_big_size((char *)s, c);
// 	ans = (char **)malloc(sizeof(char *) * (size1 + 1));
// 	while (*s != '\0')
// 	{
// 		while (*s != '\0' && defnum(*s, c) == 0)
// 			s++;
// 		if (*s != '\0')
// 		{
// 			ans[j] = each_phrase(s, c);
// 			j++;
// 		}
// 		while (*s != '\0' && defnum(*s, c) == 1)
// 			s++;
// 	}
// 	ans[j] = 0;
// 	return (ans);
// }
