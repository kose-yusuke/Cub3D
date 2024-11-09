/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:46:52 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/10 02:24:28 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calculate_wall_x(t_mgr *mgr, t_ray *ray)
{
	double	wall_x;

	if (ray->side == X_AXIS)
		wall_x = mgr->player.pos.y + ray->perpwalldist * ray->dir_y;
	else
		wall_x = mgr->player.pos.x + ray->perpwalldist * ray->dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	calculate_draw_positions(int line_height, int *draw_start, int *draw_end)
{
	*draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	*draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (*draw_start < 0)
		*draw_start = 0;
	if (*draw_end >= SCREEN_HEIGHT)
		*draw_end = SCREEN_HEIGHT - 1;
	return (0);
}

void	draw_wall(t_mgr *mgr, int x, int line_height, t_ray *ray)
{
	int		draw_start;
	int		draw_end;
	int		tex_x;
	double	step;
	double	tex_pos;

	calculate_draw_positions(line_height, &draw_start, &draw_end);
	ray->tex_side = decide_draw_texture(ray, mgr, ray->side);
	tex_x = (int)(calculate_wall_x(mgr, ray) * TEXWIDTH);
	if (ray->tex_side == EAST_WALL && ray->dir_x > 0)
		tex_x = TEXWIDTH - tex_x - 1;
	if (ray->tex_side == SOUTH_WALL && ray->dir_y < 0)
		tex_x = TEXWIDTH - tex_x - 1;
	step = 1.0 * TEXHEIGHT / line_height;
	tex_pos = (draw_start - SCREEN_HEIGHT / 2 + line_height / 2) * step;
	while (draw_start < draw_end)
	{
		tex_pos += step;
		put_pixel_to_image(mgr, x, draw_start, get_tex_pixel_color(mgr, ray,
				tex_x, (int)tex_pos & (TEXHEIGHT - 1)));
		draw_start++;
	}
}

int	render_loop(t_mgr *mgr)
{
	int		x;
	t_ray	ray;
	int		line_height;

	x = 0;
	draw_floor_and_ceiling(mgr);
	while (x < SCREEN_WIDTH)
	{
		init_ray_direction(&ray, mgr, x);
		set_ray_steps_and_initial_side_distances(&ray, mgr);
		perform_dda(&ray, mgr);
		ray.perpwalldist = get_perp_wall_dist(&ray);
		if (ray.perpwalldist == 0)
			ray.perpwalldist = 0.0000000000000001;
		line_height = (int)((SCREEN_HEIGHT) / ray.perpwalldist);
		draw_wall(mgr, x, line_height, &ray);
		x++;
	}
	mlx_put_image_to_window(mgr->mlx, mgr->win, mgr->img.img, 0, 0);
	return (0);
}
