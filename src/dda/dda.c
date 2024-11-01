/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:30:49 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/01 11:51:59 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_ray_direction(t_ray *ray, t_mgr *mgr, int x) 
{
    ray->hit = 0;
    ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
    ray->dir_x = mgr->player.dir.x + mgr->player.camera_plane.x * ray->camera_x;
    ray->dir_y = mgr->player.dir.y + mgr->player.camera_plane.y * ray->camera_x;
    ray->map_x = (int)mgr->player.pos.x;
    ray->map_y = (int)mgr->player.pos.y;

    if (ray->dir_y == 0)
		ray->delta_dist_x = INT_MAX;
	else
		ray->delta_dist_x = absolute_value(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = INT_MAX;
	else
		ray->delta_dist_y = absolute_value(1 / ray->dir_y);
}


void set_ray_steps_and_initial_side_distances(t_ray *ray, t_mgr *mgr) 
{
    if (ray->dir_x < 0) {
        ray->step_x = -1;
        ray->side_dist_x = (mgr->player.pos.x - ray->map_x) * ray->delta_dist_x;
    } else {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - mgr->player.pos.x) * ray->delta_dist_x;
    }

    if (ray->dir_y < 0) {
        ray->step_y = -1;
        ray->side_dist_y = (mgr->player.pos.y - ray->map_y) * ray->delta_dist_y;
    } else {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - mgr->player.pos.y) * ray->delta_dist_y;
    }
}

void perform_dda(t_ray *ray, t_mgr *mgr) 
{
    ray->side = 0;

    while (ray->hit == 0) 
    {
        if (ray->side_dist_x < ray->side_dist_y) 
        {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        } 
        else 
        {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        if (mgr->map.grid[ray->map_y][ray->map_x] == '1')
            ray->hit = 1;
    }
}
