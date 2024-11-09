/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:39:44 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/09 15:15:11 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_and_ceiling(t_mgr *mgr)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			put_pixel_to_image(mgr, x, y, mgr->textures->color_ceiling);
			put_pixel_to_image(mgr, x, SCREEN_HEIGHT - y - 1,
				mgr->textures->color_floor);
			x++;
		}
		y++;
	}
}
