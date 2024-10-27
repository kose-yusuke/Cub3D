/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:04:00 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/10/27 17:46:09 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_error_message_handler(char *message)
{
	printf("%s\n%s\n","Error",message);
	return (0);
}

void init_mgr(t_mgr *mgr, char* map_filepath)
{
	// mgr->collect_flag = 0;
	// mgr->move_count = 0;
	// mgr->char_counters.player_counter = 0;
	// mgr->char_counters.collect_counter = 0;
	// mgr->char_counters.exit_counter = 0;
	// mgr->maps.row = count_rows(mgr, map_filepath);
}

int ft_init_render(t_mgr *mgr)
{
	mgr->mlx = mlx_init();
	mgr->win = mlx_new_window(mgr->mlx, 500, 500, WINDOW_NAME);

	// ft_read_management(mgr);
	// if(!ft_render_map(mgr))
	// 	return (0);
	mlx_hook(mgr->win, ON_KEYDOWN, 1L << 0, ft_event_handler, mgr);
	mlx_hook(mgr->win, ON_DESTROY, 1L << 17, ft_close, mgr);
	// mlx_loop_hook(mgr->mlx, ft_update_render_map, mgr);
	mlx_loop(mgr->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mgr	mgr;

	if (argc != 2)
		return (ft_error_message_handler("Usage: ./cub3D <map_name>.cub"));
	init_mgr(&mgr, argv[1]);
	// init_textures(&mgr);
	// print_controls();
	// render_images(&mgr);
	// listen_for_input(&mgr);
    ft_init_render(&mgr);
	return (0);
}
