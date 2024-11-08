/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:52:10 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/08 13:53:39 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_position(t_mgr *mgr, int x, int y)
{
	mgr->player.pos.x = (double)x;
	mgr->player.pos.y = (double)y;
}

void	set_north_south_direction(t_mgr *mgr, char compass)
{
	if (compass == 'N')
	{
		mgr->player.dir.x = 0;
		mgr->player.dir.y = -1;
		mgr->player.camera_plane.x = 0.66;
		mgr->player.camera_plane.y = 0;
	}
	else if (compass == 'S')
	{
		mgr->player.dir.x = 0;
		mgr->player.dir.y = 1;
		mgr->player.camera_plane.x = -0.66;
		mgr->player.camera_plane.y = 0;
	}
}

void	set_east_west_direction(t_mgr *mgr, char compass)
{
	if (compass == 'E')
	{
		mgr->player.dir.x = 1;
		mgr->player.dir.y = 0;
		mgr->player.camera_plane.x = 0;
		mgr->player.camera_plane.y = 0.66;
	}
	else if (compass == 'W')
	{
		mgr->player.dir.x = -1;
		mgr->player.dir.y = 0;
		mgr->player.camera_plane.x = 0;
		mgr->player.camera_plane.y = -0.66;
	}
}

void	set_player_direction(t_mgr *mgr, char compass)
{
	if (compass == 'N' || compass == 'S')
		set_north_south_direction(mgr, compass);
	else if (compass == 'E' || compass == 'W')
		set_east_west_direction(mgr, compass);
}

void	init_player(t_mgr *mgr, int x, int y, char compass)
{
	set_player_position(mgr, x, y);
	set_player_direction(mgr, compass);
}
