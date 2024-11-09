/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:29:04 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/10 02:24:47 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

double	get_perp_wall_dist(t_ray *ray)
{
	if (ray->side == 0)
		return (ray->side_dist_x - ray->delta_dist_x);
	else
		return (ray->side_dist_y - ray->delta_dist_y);
}

int	get_tex_pixel_color(t_mgr *mgr, t_ray *ray, int tex_x, int tex_y)
{
	int	color;

	color = *(unsigned int *)(mgr->wall_img[ray->tex_side].addr + (tex_y
				* mgr->wall_img[ray->tex_side].line_length + tex_x
				* (mgr->wall_img[ray->tex_side].bits_per_pixel / 8)));
	return (color);
}
