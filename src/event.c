/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:32:02 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/10/30 20:51:48 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//destroy window
int ft_close(t_mgr *mgr)
{
	mlx_destroy_window(mgr->mlx, mgr->win);
    exit(0);
}

// void	ft_update_position(t_mgr *mgr, int x, int y)
// {
// 	if (mgr->map.grid[y][x] == '0')
// 	{
//         mgr->player.pos.x = x;
//         mgr->player.pos.y = y;
//     }
//     printf("x: %d, y: %d\n", x, y);
// }

int ft_move_player(int keycode, t_mgr *mgr)
{
    if (keycode == UP)
    {
        if(mgr->map.grid[(int)(mgr->player.pos.x + mgr->player.dir.x * MOVESPEED)][(int)(mgr->player.pos.y)] == '0') 
            mgr->player.pos.x += mgr->player.dir.x * MOVESPEED;
        if(mgr->map.grid[(int)(mgr->player.pos.x)][(int)(mgr->player.pos.y + mgr->player.dir.y * MOVESPEED)] == '0') 
            mgr->player.pos.y += mgr->player.dir.y * MOVESPEED;
    }
    else if (keycode == DOWN)
    {
        if(mgr->map.grid[(int)(mgr->player.pos.x - mgr->player.dir.x * MOVESPEED)][(int)(mgr->player.pos.y)] == '0') 
            mgr->player.pos.x -= mgr->player.dir.x * MOVESPEED;
        if(mgr->map.grid[(int)(mgr->player.pos.x)][(int)(mgr->player.pos.y - mgr->player.dir.y * MOVESPEED)] == '0') 
            mgr->player.pos.y -= mgr->player.dir.y * MOVESPEED;
    }
    // else if (keycode == LEFT)
    //     ft_update_position(mgr, mgr->player.pos.x - 1, mgr->player.pos.y);
    // else if (keycode == RIGHT) 
    //     ft_update_position(mgr, mgr->player.pos.x + 1, mgr->player.pos.y);
    if (keycode == RIGHT_VIEW)
    {
      //both camera direction and camera plane must be rotated
        double oldDirX = mgr->player.dir.x;
        mgr->player.dir.x = mgr->player.dir.x * cos(-ROTSPEED) - mgr->player.dir.y * sin(-ROTSPEED);
        mgr->player.pos.y = oldDirX * sin(-ROTSPEED) + mgr->player.pos.y * cos(-ROTSPEED);
        double oldPlaneX = mgr->player.camera_plane.x;
        mgr->player.camera_plane.x = mgr->player.camera_plane.x * cos(-ROTSPEED) - mgr->player.camera_plane.y * sin(-ROTSPEED);
        mgr->player.camera_plane.y = oldPlaneX * sin(-ROTSPEED) + mgr->player.camera_plane.y * cos(-ROTSPEED);
    }
    if (keycode == LEFT_VIEW)
    {
        double oldDirX = mgr->player.dir.x;
        mgr->player.dir.x = mgr->player.dir.x * cos(ROTSPEED) - mgr->player.dir.y * sin(ROTSPEED);
        mgr->player.dir.y = oldDirX * sin(ROTSPEED) + mgr->player.dir.y * cos(ROTSPEED);
        double oldPlaneX = mgr->player.camera_plane.x;
        mgr->player.camera_plane.x = mgr->player.camera_plane.x * cos(ROTSPEED) - mgr->player.camera_plane.y * sin(ROTSPEED);
        mgr->player.camera_plane.y = oldPlaneX * sin(ROTSPEED) + mgr->player.camera_plane.y * cos(ROTSPEED);
    }
    return (0);
}

//if pressed ESC, window closed
int ft_event_handler(int keycode, t_mgr *mgr)
{
    if (keycode == ESC)
        ft_close(mgr);
    else
        ft_move_player(keycode, mgr);
    return (0);
}