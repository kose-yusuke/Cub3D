/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:42:28 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/10/27 17:32:55 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

// MACRO
# define SQUARE_SIZE 32
# define WINDOW_NAME "cub3D"

// STRUCTURE
typedef enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}					t_event;

typedef enum e_keycode
{
	ESC = 65307,
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100
}				t_keycode;

typedef struct s_mgr
{
    void *mlx;
	void *win;
	// t_pos 	player_pos;
	// t_pos 	exit_pos;
	// t_textures  	textures;
	// t_maps			maps;
	// t_char_counters char_counters;
	// int collect_flag;
	// int move_count;
}               t_mgr;


// FUNCTION

int ft_event_handler(int keycode, t_mgr *mgr);
int ft_close(t_mgr *mgr);


#endif