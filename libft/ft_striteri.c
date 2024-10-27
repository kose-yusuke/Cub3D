/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striteri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:06:55 by ykoseki           #+#    #+#             */
/*   Updated: 2023/05/28 15:36:41 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	len;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	len = ft_strlen((char *)s);
	while (len > 0)
	{
		f(i, s + i);
		i++;
		len--;
	}
}
