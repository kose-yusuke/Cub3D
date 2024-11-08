/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:46:52 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/08 12:45:51 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_perp_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		return (ray->side_dist_x - ray->delta_dist_x);
	else
		return (ray->side_dist_y - ray->delta_dist_y);
}

void	init_image(t_mgr *mgr)
{
	mgr->img.img = mlx_new_image(mgr->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mgr->img.addr = mlx_get_data_addr(mgr->img.img, &mgr->img.bits_per_pixel,
			&mgr->img.line_length, &mgr->img.endian);
}

void	put_pixel_to_image(t_mgr *mgr, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = mgr->img.addr + (y * mgr->img.line_length + x
			* (mgr->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_wall(t_mgr *mgr, int x, int line_height, int side, t_ray *ray)
{
	int		draw_start;
	int		draw_end;
	int		color;
	int		y;
	int		tex_x;
	int		tex_y;
	int		texture;
	double	wallX;
	double	step;
	double	tex_pos;

	draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	if (ray->side == X_AXIS)
		wallX = mgr->player.pos.y + ray->perpWallDist * ray->dir_y;
	else
		wallX = mgr->player.pos.x + ray->perpWallDist * ray->dir_x;
	wallX -= floor(wallX);
	tex_x = (int)(wallX * texWidth);
	if (texture == EAST_WALL && ray->dir_x > 0)
		tex_x = texWidth - tex_x - 1;
	if (texture == SOUTH_WALL && ray->dir_y < 0)
		tex_x = texWidth - tex_x - 1;
	step = 1.0 * texHeight / line_height;
	tex_pos = (draw_start - SCREEN_HEIGHT / 2 + line_height / 2) * step;
	texture = decide_draw_texture(ray, mgr, side);
    y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)tex_pos & (texHeight - 1);
		tex_pos += step;
		color = *(unsigned int *)(mgr->wall_img[texture].addr + (tex_y
					* mgr->wall_img[texture].line_length + tex_x
					* (mgr->wall_img[texture].bits_per_pixel / 8)));
		put_pixel_to_image(mgr, x, y, color);
		y++;
	}
}

int	render_loop(t_mgr *mgr)
{
	int		x;
	t_ray	ray;
	int		line_height;

	x = 0;
	castFloorAndCeiling(mgr);
	while (x < SCREEN_WIDTH)
	{
		init_ray_direction(&ray, mgr, x);
		// print_grid(mgr);
		set_ray_steps_and_initial_side_distances(&ray, mgr);
		perform_dda(&ray, mgr);
		ray.perpWallDist = get_perp_wall_dist(&ray);
		if (ray.perpWallDist == 0)
			ray.perpWallDist = 0.0000000000000001;
		line_height = 0;
		line_height = (int)((SCREEN_HEIGHT) / ray.perpWallDist);
		draw_wall(mgr, x, line_height, ray.side, &ray);
		x++;
	}
	mlx_put_image_to_window(mgr->mlx, mgr->win, mgr->img.img, 0, 0);
	return (0);
}
