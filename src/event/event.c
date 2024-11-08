/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:32:02 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/08 13:44:14 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward_backward(int keycode, t_mgr *mgr)
{
	if (keycode == UP)
	{
		if (mgr->map.grid[(int)(mgr->player.pos.x + mgr->player.dir.x
				* MOVESPEED)][(int)(mgr->player.pos.y)] == '0')
			mgr->player.pos.x += mgr->player.dir.x * MOVESPEED;
		if (mgr->map.grid[(int)(mgr->player.pos.x)][(int)(mgr->player.pos.y
				+ mgr->player.dir.y * MOVESPEED)] == '0')
			mgr->player.pos.y += mgr->player.dir.y * MOVESPEED;
	}
	else if (keycode == DOWN)
	{
		if (mgr->map.grid[(int)(mgr->player.pos.x - mgr->player.dir.x
				* MOVESPEED)][(int)(mgr->player.pos.y)] == '0')
			mgr->player.pos.x -= mgr->player.dir.x * MOVESPEED;
		if (mgr->map.grid[(int)(mgr->player.pos.x)][(int)(mgr->player.pos.y
				- mgr->player.dir.y * MOVESPEED)] == '0')
			mgr->player.pos.y -= mgr->player.dir.y * MOVESPEED;
	}
}

void	move_left_right(int keycode, t_mgr *mgr)
{
	if (keycode == LEFT)
	{
		if (mgr->map.grid[(int)(mgr->player.pos.x - mgr->player.dir.y
				* MOVESPEED)][(int)(mgr->player.pos.y)] == '0')
			mgr->player.pos.x += mgr->player.dir.y * MOVESPEED;
		if (mgr->map.grid[(int)(mgr->player.pos.x)][(int)(mgr->player.pos.y
				+ mgr->player.dir.x * MOVESPEED)] == '0')
			mgr->player.pos.y -= mgr->player.dir.x * MOVESPEED;
	}
	else if (keycode == RIGHT)
	{
		if (mgr->map.grid[(int)(mgr->player.pos.x + mgr->player.dir.y
				* MOVESPEED)][(int)(mgr->player.pos.y)] == '0')
			mgr->player.pos.x -= mgr->player.dir.y * MOVESPEED;
		if (mgr->map.grid[(int)(mgr->player.pos.x)][(int)(mgr->player.pos.y
				- mgr->player.dir.x * MOVESPEED)] == '0')
			mgr->player.pos.y += mgr->player.dir.x * MOVESPEED;
	}
}

void	rotate_view(int keycode, t_mgr *mgr)
{
	double	olddirx;
	double	oldplanex;
	double	rotation;

	if (keycode == LEFT_VIEW)
		rotation = -ROTSPEED;
	else
		rotation = ROTSPEED;
	olddirx = mgr->player.dir.x;
	mgr->player.dir.x = mgr->player.dir.x * cos(rotation) - mgr->player.dir.y
		* sin(rotation);
	mgr->player.dir.y = olddirx * sin(rotation) + mgr->player.dir.y
		* cos(rotation);
	oldplanex = mgr->player.camera_plane.x;
	mgr->player.camera_plane.x = mgr->player.camera_plane.x * cos(rotation)
		- mgr->player.camera_plane.y * sin(rotation);
	mgr->player.camera_plane.y = oldplanex * sin(rotation)
		+ mgr->player.camera_plane.y * cos(rotation);
}

int	ft_move_player(int keycode, t_mgr *mgr)
{
	if (keycode == UP || keycode == DOWN)
		move_forward_backward(keycode, mgr);
	else if (keycode == LEFT || keycode == RIGHT)
		move_left_right(keycode, mgr);
	else if (keycode == LEFT_VIEW || keycode == RIGHT_VIEW)
		rotate_view(keycode, mgr);
	return (0);
}

int	ft_event_handler(int keycode, t_mgr *mgr)
{
	if (keycode == ESC)
		ft_close(mgr);
	else
		ft_move_player(keycode, mgr);
	printf("%s%f%s%f\n", "position: x: ", mgr->player.pos.x, " y : ",
		mgr->player.pos.y);
	printf("%s%f%s%f\n", "direction: x: ", mgr->player.dir.x, " y : ",
		mgr->player.dir.y);
	return (0);
}
