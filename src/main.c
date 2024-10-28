/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:04:00 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/10/28 15:47:24 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <libc.h>

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q cub3D");
// }

// void print_grid(t_mgr *mgr)
// {
//     int i = 0;
    
//     while (mgr->map.grid[i] != NULL && i < mgr->map.row)
//     {
//         printf("%s", mgr->map.grid[i]);
//         i++;
//     }
// }

void init_mgr(t_mgr *mgr, char* map_filepath)
{
    mgr->textures = malloc(sizeof(t_textures));
    if (!mgr->textures)
        exit(ft_error_message_handler("Failed to allocate memory for textures"));
    mgr->map.row = count_rows(mgr, map_filepath);
    mgr->map.grid = read_cub_file(mgr, map_filepath);
    //mapのvalidity

    //textureのvalidity

    // init_player(&mgr->player);
}

int ft_update_render_map(t_mgr *mgr)
{
    
    return (0);
}


int ft_init_render(t_mgr *mgr)
{
	mgr->mlx = mlx_init();
    if (!mgr->mlx)
        exit(1);
	mgr->win = mlx_new_window(mgr->mlx, 500, 500, WINDOW_NAME);
    if (!mgr->win)
        exit(1);
	ft_set_xpmfile(mgr);
    // ↓dda
	// if(!ft_render_map(mgr))
	// 	return (0);
	mlx_hook(mgr->win, ON_KEYDOWN, 1L << 0, ft_event_handler, mgr);
	mlx_hook(mgr->win, ON_DESTROY, 1L << 17, ft_close, mgr);
	mlx_loop_hook(mgr->mlx, ft_update_render_map, mgr);
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
