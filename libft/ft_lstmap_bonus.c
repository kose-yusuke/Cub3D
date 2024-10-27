/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:33:03 by ykoseki           #+#    #+#             */
/*   Updated: 2023/06/03 22:49:32 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*output;

	if (!lst || !f)
		return (NULL);
	tmp = ft_lstnew((*f)(lst->content));
	if (!tmp || !del)
		return (NULL);
	output = tmp;
	if (!output)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		output->next = ft_lstnew((*f)(lst->content));
		if (output->next == NULL)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		output = output->next;
	}
	return (tmp);
}
