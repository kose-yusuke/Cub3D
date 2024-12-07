/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:26:47 by sakitaha          #+#    #+#             */
/*   Updated: 2024/12/07 14:10:59 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_up_grid(char **grid, int rows)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (i < rows)
	{
		xfree(grid[i]);
		i++;
	}
	xfree(grid);
}
