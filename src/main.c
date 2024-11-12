/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:04:00 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/13 03:36:42 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <libc.h>

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q cub3D");
// }

void	init_mgr(t_mgr *mgr, char *map_filepath)
{
	mgr->textures = malloc(sizeof(t_textures));
	if (!mgr->textures)
		exit(ft_error_message_handler("Failed to allocate memory for tex"));
	mgr->map.row = count_rows(mgr, map_filepath);
	mgr->map.grid = read_cub_file(mgr, map_filepath);
	mgr->map.column = count_columns(mgr) - 1;
	if (check_map_validity(mgr) == 1)
		exit(1);
}

void	set_floor_color(t_mgr *mgr, int red, int green, int blue)
{
	mgr->textures->color_floor = (red << 16) | (green << 8) | (blue);
}

void	set_ceiling_color(t_mgr *mgr, int red, int green, int blue)
{
	mgr->textures->color_ceiling = (red << 16) | (green << 8) | (blue);
}

int	ft_init_render(t_mgr *mgr)
{
	mgr->mlx = mlx_init();
	if (!mgr->mlx)
		exit(1);
	mgr->win = mlx_new_window(mgr->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			WINDOW_NAME);
	if (!mgr->win)
		exit(1);
	init_image(mgr);
	ft_set_xpmfile(mgr);
	set_floor_color(mgr, mgr->textures->f_rgb.red, mgr->textures->f_rgb.green,
		mgr->textures->f_rgb.blue);
	set_ceiling_color(mgr, mgr->textures->c_rgb.red, mgr->textures->c_rgb.green,
		mgr->textures->c_rgb.blue);
	render_loop(mgr);
	mlx_hook(mgr->win, ON_KEYDOWN, 1L << 0, ft_event_handler, mgr);
	mlx_hook(mgr->win, ON_DESTROY, 1L << 17, ft_close, mgr);
	mlx_loop_hook(mgr->mlx, render_loop, mgr);
	mlx_loop(mgr->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mgr	mgr;

	if (argc != 2 || !is_valid_extension(argv[1], ".cub"))
		return (ft_error_message_handler("Usage: ./cub3D <map_name>.cub"));
	validate_map(&(mgr.map), argv[1]);
	init_mgr(&mgr, argv[1]);
	ft_init_render(&mgr);
	return (0);
}
