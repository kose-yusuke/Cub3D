/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoseki <ykoseki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:17:02 by ykoseki           #+#    #+#             */
/*   Updated: 2023/05/28 15:34:53 by ykoseki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	while (len > 0)
	{
		ft_putchar_fd(*s, fd);
		s++;
		len--;
	}
}
