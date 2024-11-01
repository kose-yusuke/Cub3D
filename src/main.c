/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:04:00 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/01 11:10:46 by koseki.yusu      ###   ########.fr       */
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

void init_player(t_mgr *mgr, int x, int y, char compass) 
{
    mgr->player.pos.x = (double)x;
    mgr->player.pos.y = (double)y;
    
    if (compass == 'N')
    {
        mgr->player.dir.x = 0;
		mgr->player.dir.y = -1;
		mgr->player.camera_plane.x = 0.66;
		mgr->player.camera_plane.y = 0;
    }
    else if (compass == 'S')
    {
        mgr->player.dir.x = 0;
		mgr->player.dir.y = 1;
		mgr->player.camera_plane.x = -0.66;
		mgr->player.camera_plane.y = 0;
    }
    else if (compass == 'W')
    {
        mgr->player.dir.x = -1;
		mgr->player.dir.y = 0;
		mgr->player.camera_plane.x = 0;
		mgr->player.camera_plane.y = -0.66;
    }
    else if (compass == 'E')
    {
        mgr->player.dir.x = 1;
		mgr->player.dir.y = 0;
		mgr->player.camera_plane.x = 0;
		mgr->player.camera_plane.y = 0.66;
    }
}

int check_map_validity(t_mgr *mgr) 
{
    int spawn_count = 0;
    int i = 0;
    int j = 0;
    char cell = '\0';
    while (i < mgr->map.row) 
    {
        j = 0;
        while (j < mgr->map.column)
        {
            cell = mgr->map.grid[i][j];
            //1(壁), 0(空間), NSWE以外の文字がないか
            if (!is_valid_char(cell)) 
            {
                return (ft_error_message_handler("Error: Invalid character in map\n"));   
            }
            //playerの初期化
            if (cell == 'N' || cell == 'S' || cell == 'W' || cell == 'E') 
            {
                if (spawn_count > 0) 
                    return (ft_error_message_handler("Error: Multiple player starting positions\n"));
                spawn_count = 1;
                init_player(mgr, i, j, cell);
            }
            j++;
        }
        i++;
    }
    // プレイヤーが1つも見つからない場合のエラー
    if (spawn_count == 0) 
        return (ft_error_message_handler("Error: No player starting position found\n"));
    return (0);
}


void init_mgr(t_mgr *mgr, char* map_filepath)
{
    mgr->textures = malloc(sizeof(t_textures));
    if (!mgr->textures)
        exit(ft_error_message_handler("Failed to allocate memory for textures"));
    mgr->map.row = count_rows(mgr, map_filepath);
    mgr->map.grid = read_cub_file(mgr, map_filepath);
    mgr->map.column = count_columns(mgr) - 1;
    //mapのvalidity(init_player)
    if (check_map_validity(mgr) == 1)
        exit(1);
    //textureのvalidity

}

int ft_init_render(t_mgr *mgr)
{
	mgr->mlx = mlx_init();
    if (!mgr->mlx)
        exit(1);
	mgr->win = mlx_new_window(mgr->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
    if (!mgr->win)
        exit(1);
    init_image(mgr);
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
