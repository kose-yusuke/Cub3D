/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:30:14 by ykoseki           #+#    #+#             */
/*   Updated: 2023/05/28 09:25:31 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!del || !lst)
		return ;
	tmp2 = *lst;
	while (tmp2 != NULL)
	{
		tmp = tmp2->next;
		ft_lstdelone(tmp2, *del);
		tmp2 = tmp;
	}
	*lst = NULL;
}
