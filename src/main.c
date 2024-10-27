/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:04:00 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/10/27 23:22:07 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_error_message_handler(char *message)
{
	printf("%s\n%s\n","Error",message);
	return (1);
}

void init_mgr(t_mgr *mgr, char* map_filepath)
{
	//argのparse

    //mapのvalidity

    //textureのvalidity

    // init_player(&mgr->player);
}


int ft_init_render(t_mgr *mgr)
{
	mgr->mlx = mlx_init();
    if (!mgr->mlx)
        exit(1);
	mgr->win = mlx_new_window(mgr->mlx, 500, 500, WINDOW_NAME);
    if (!mgr->win)
        exit(1);
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
    ft_init_render(&mgr);
	return (0);
}
