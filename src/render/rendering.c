/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:46:52 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/10/30 21:33:18 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double get_perp_wall_dist(t_ray *ray) 
{
    if (ray->side == 0)
        return ray->side_dist_x - ray->delta_dist_x;
    else
        return ray->side_dist_y - ray->delta_dist_y;
}

void draw_wall(t_mgr *mgr, int x, int line_height, int side, t_ray ray) {
    int draw_start;
    int draw_end;
    int color;

    draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
    draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
    if (draw_start < 0)
        draw_start = 0;
    if (draw_end >= SCREEN_HEIGHT)
        draw_end = SCREEN_HEIGHT - 1;
    printf("aaa");
    printf("%c\n",mgr->map.grid[ray.map_x][ray.map_y]);
    printf("aaa");
    switch(mgr->map.grid[ray.map_x][ray.map_y])
    {
        case '1':  color = 0xFF0000; break; // 赤 (RGB_Red)
        case '2':  color = 0x00FF00; break; // 緑 (RGB_Green)
        case '3':  color = 0x0000FF; break; // 青 (RGB_Blue)
        case '4':  color = 0xFFFFFF; break; // 白 (RGB_White)
        default: color = 0xFFFF00; break; // 黄 (RGB_Yellow)
    }

    // if (side == 1) {color = color / 2;}

    int y = draw_start;
    while (y < draw_end) {
        mlx_pixel_put(mgr->mlx, mgr->win, x, y, color);
        y++;
    }
}

int render_loop(t_mgr *mgr) 
{
    int x = 0;

    while (x < SCREEN_WIDTH)
    {
        t_ray ray;
        double perp_wall_dist;
        int line_height;
        
        init_ray_direction(&ray, mgr, x);
        // print_grid(mgr);
        set_ray_steps_and_initial_side_distances(&ray, mgr);
        perform_dda(&ray, mgr);
        perp_wall_dist = get_perp_wall_dist(&ray);
        if (perp_wall_dist == 0)
            perp_wall_dist = 0.000000001;
        line_height = 0;
        line_height = (int)((SCREEN_HEIGHT / 50) / perp_wall_dist);
        draw_wall(mgr, x, line_height, ray.side, ray);
        x++;
    }
    return (0);
}
