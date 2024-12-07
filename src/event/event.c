/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:32:02 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/17 00:13:32 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward_backward(int keycode, t_mgr *mgr)
{
	float	new_x;
	float	new_y;

	if (keycode == UP)
	{
		new_x = mgr->player.pos.x + mgr->player.dir.x * MOVESPEED;
		new_y = mgr->player.pos.y + mgr->player.dir.y * MOVESPEED;
		if (mgr->map.grid[(int)(mgr->player.pos.y)][(int)new_x] != '1' &&
			mgr->map.grid[(int)new_y][(int)(mgr->player.pos.x)] != '1')
		{
			mgr->player.pos.x = new_x;
			mgr->player.pos.y = new_y;
		}
	}
	else if (keycode == DOWN)
	{
		new_x = mgr->player.pos.x - mgr->player.dir.x * MOVESPEED;
		new_y = mgr->player.pos.y - mgr->player.dir.y * MOVESPEED;
		if (mgr->map.grid[(int)(mgr->player.pos.y)][(int)new_x] != '1' &&
			mgr->map.grid[(int)new_y][(int)(mgr->player.pos.x)] != '1')
		{
			mgr->player.pos.x = new_x;
			mgr->player.pos.y = new_y;
		}
	}
}

void	move_left_right(int keycode, t_mgr *mgr)
{
	float	new_x;
	float	new_y;

	if (keycode == RIGHT)
	{
		new_x = mgr->player.pos.x - mgr->player.dir.y * MOVESPEED;
		new_y = mgr->player.pos.y + mgr->player.dir.x * MOVESPEED;
		if (mgr->map.grid[(int)(mgr->player.pos.y)][(int)new_x] != '1' &&
			mgr->map.grid[(int)new_y][(int)(mgr->player.pos.x)] != '1')
		{
			mgr->player.pos.x = new_x;
			mgr->player.pos.y = new_y;
		}
	}
	else if (keycode == LEFT)
	{
		new_x = mgr->player.pos.x + mgr->player.dir.y * MOVESPEED;
		new_y = mgr->player.pos.y - mgr->player.dir.x * MOVESPEED;
		if (mgr->map.grid[(int)(mgr->player.pos.y)][(int)new_x] != '1' &&
			mgr->map.grid[(int)new_y][(int)(mgr->player.pos.x)] != '1')
		{
			mgr->player.pos.x = new_x;
			mgr->player.pos.y = new_y;
		}
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
	return (0);
}
