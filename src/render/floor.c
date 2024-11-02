/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:39:44 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/02 23:31:50 by koseki.yusu      ###   ########.fr       */
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
			put_pixel_to_image(mgr, x, y,
				(mgr->textures->c_rgb.red << 16) | (mgr->textures->c_rgb.green << 8) | (mgr->textures->c_rgb.blue));
			put_pixel_to_image(mgr, x, SCREEN_HEIGHT - y - 1,
				(mgr->textures->f_rgb.red << 16) | (mgr->textures->f_rgb.green << 8) | (mgr->textures->f_rgb.blue));
			x++;
		}
		y++;
	}
}

void	calculateFloorCeilingSteps(t_mgr *mgr, float rowDistance,
		float *floorStepX, float *floorStepY, float *floorX, float *floorY)
{
	float	rayDirX0;
	float	rayDirY0;
	float	rayDirX1;
	float	rayDirY1;

	rayDirX0 = mgr->player.dir.x - mgr->player.camera_plane.x;
	rayDirY0 = mgr->player.dir.y - mgr->player.camera_plane.y;
	rayDirX1 = mgr->player.dir.x + mgr->player.camera_plane.x;
	rayDirY1 = mgr->player.dir.y + mgr->player.camera_plane.y;
	*floorStepX = rowDistance * (rayDirX1 - rayDirX0) / SCREEN_WIDTH;
	*floorStepY = rowDistance * (rayDirY1 - rayDirY0) / SCREEN_WIDTH;
	*floorX = mgr->player.pos.x + rowDistance * rayDirX0;
	*floorY = mgr->player.pos.y + rowDistance * rayDirY0;
}

void	castFloorAndCeiling(t_mgr *mgr)
{
	int		y;
	int		p;
	float	rowDistance;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		float floorX, floorY, floorStepX, floorStepY;
		p = y - SCREEN_HEIGHT / 2;
		rowDistance = 0.5 * SCREEN_HEIGHT / p;
		calculateFloorCeilingSteps(mgr, rowDistance, &floorStepX, &floorStepY,
			&floorX, &floorY);
		draw_floor_and_ceiling(mgr);
		y++;
	}
}
