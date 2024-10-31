/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:46:52 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/10/31 14:25:41 by koseki.yusu      ###   ########.fr       */
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

// イメージデータの初期化
void init_image(t_mgr *mgr)
{
    mgr->img.img = mlx_new_image(mgr->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    mgr->img.addr = mlx_get_data_addr(mgr->img.img, &mgr->img.bits_per_pixel,
                                    &mgr->img.line_length, &mgr->img.endian);
}

// ピクセルをバッファに書き込む
void put_pixel_to_image(t_mgr *mgr, int x, int y, int color)
{
    char	*dst;
    
    // バッファ範囲内にあるか確認
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
        return;

    // ピクセル位置のポインタを計算して代入
    dst = mgr->img.addr + (y * mgr->img.line_length + x * (mgr->img.bits_per_pixel / 8));
    *(unsigned int *)dst = color;
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
    if (ray.map_y > -1 && ray.map_y > -1)
    {
        if (mgr->map.grid[ray.map_x][ray.map_y] == '1')
            color = 0xFF0000;
        else
            color = 0x000000;
    }
    
    int y = draw_start;
    while (y < draw_end) {
        put_pixel_to_image(mgr, x, y, color);
        y++;
    }
}

int render_loop(t_mgr *mgr) 
{
    int x = 0;

    init_image(mgr);
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
        line_height = (int)((SCREEN_HEIGHT) / perp_wall_dist);
        draw_wall(mgr, x, line_height, ray.side, ray);
        x++;
    }
    mlx_put_image_to_window(mgr->mlx, mgr->win, mgr->img.img, 0, 0);
	mlx_destroy_image(mgr->mlx, mgr->img.img);
    return (0);
}

