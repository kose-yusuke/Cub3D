/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:31:32 by ykoseki           #+#    #+#             */
/*   Updated: 2023/06/23 16:19:06 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

// #include <ctype.h>
// // static void str_toupper(void *p)
// // {
// //     char *str = (char *)p;
// //     while (*str)
// //     {
// //         *str = toupper(*str);
// //         str++;
// //     }
// // }

// static void str_tolower(void *p)
// {
//     char *str = (char *)p;
//     while (*str)
//     {
//         *str = tolower(*str);
//         str++;
//     }
// }

// #include <stdio.h>

// int	main(void)
// {
//     // t_list  *lst = ft_lstnew(strdup("Hello"));
//     // ft_lstadd_back(&lst, ft_lstnew(strdup(" World")));
//     // ft_lstadd_back(&lst, ft_lstnew(strdup(" 42")));
//     // ft_lstadd_back(&lst, ft_lstnew(strdup(" Tokyo!")));
//     // ft_lstadd_back(&lst, ft_lstnew(strdup("")));

// 	t_list *l = ft_lstnew(strdup("KO !"));

// 	l->next = ft_lstnew(strdup("KO !"));
// 	l->next->next = ft_lstnew(strdup("KO !"));
// 	ft_lstiter(l, str_tolower);
// 	printf("%s", l->next->next->content);

//     // toupper
//     // ft_lstiter(lst, str_toupper);
// 	// printf("%s", lst->content);
//     // /* 1 */ ASSERT_EQ_STR(lst->content, "HELLO");
//     // /* 2 */ ASSERT_EQ_STR(lst->next->content, " WORLD");
//     // /* 3 */ ASSERT_EQ_STR(lst->next->next->content, " 42");
//     // /* 4 */ ASSERT_EQ_STR(lst->next->next->next->content, " TOKYO!");
//     // /* 5 */ ASSERT_EQ_STR(lst->next->next->next->next->content, "");
//     // /* 6 */ ASSERT_EQ_PTR(lst->next->next->next->next->next, NULL);

//     // // tolower
//     // ft_lstiter(lst, str_tolower);
//     // /* 7 */ ASSERT_EQ_STR(lst->content, "hello");
//     // /* 8 */ ASSERT_EQ_STR(lst->next->content, " world");
//     // /* 9 */ ASSERT_EQ_STR(lst->next->next->content, " 42");
//     // /* 10 */ ASSERT_EQ_STR(lst->next->next->next->content, " tokyo!");
//     // /* 11 */ ASSERT_EQ_STR(lst->next->next->next->next->content, "");
//     // /* 12 */ ASSERT_EQ_PTR(lst->next->next->next->next->next, NULL);
// }