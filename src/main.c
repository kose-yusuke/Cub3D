/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:04:00 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/10/30 21:13:12 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <libc.h>

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q cub3D");
// }

void print_grid(t_mgr *mgr)
{
    int i = 0;
    
    while (mgr->map.grid[i] != NULL && i < mgr->map.row)
    {
        printf("%s", mgr->map.grid[i]);
        i++;
    }
    printf("%s", "\n");
}

//仮
void init_player(t_mgr *mgr) 
{
    mgr->player.pos.x = 12.1;
    mgr->player.pos.y = 12.7;
    mgr->player.dir.x = 1;
    mgr->player.dir.y = 0;
    mgr->player.camera_plane.x = 0.0;
    mgr->player.camera_plane.y = 0.66;
}

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
    init_player(mgr);
}

int ft_init_render(t_mgr *mgr)
{
	mgr->mlx = mlx_init();
    if (!mgr->mlx)
        exit(1);
	mgr->win = mlx_new_window(mgr->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    if (!mgr->win)
        exit(1);
    ft_set_xpmfile(mgr);
	mlx_hook(mgr->win, ON_KEYDOWN, 1L << 0, ft_event_handler, mgr);
	mlx_hook(mgr->win, ON_DESTROY, 1L << 17, ft_close, mgr);
	mlx_loop_hook(mgr->mlx, render_loop, mgr);
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
