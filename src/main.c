/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:04:00 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/13 03:21:38 by sakitaha         ###   ########.fr       */
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
	mgr->textures->color_ceiling = (mgr->textures->c_rgb.red << 16) | (mgr->textures->c_rgb.green << 8) | (mgr->textures->c_rgb.blue);
	mgr->textures->color_floor = (mgr->textures->f_rgb.red << 16) | (mgr->textures->f_rgb.green << 8) | (mgr->textures->f_rgb.blue);
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
	// validate_map(&(mgr.map), argv[1]);
	init_mgr(&mgr, argv[1]);
	ft_init_render(&mgr);
	// mlx_destroy_image(&mgr->mlx, &mgr->img.img);
	return (0);
}
