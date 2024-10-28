/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:42:28 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/10/28 15:46:12 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

// MACRO
# define SQUARE_SIZE 32
# define WINDOW_NAME "cub3D"

// valid char
# define WALL '1'
# define SPACE '0'
# define PLAYER 'P'
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'

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
}				t_event;

typedef enum e_keycode
{
	ESC = 65307,
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100
}				t_keycode;

typedef struct s_vec2d
{
	double		x;
	double		y;
}				t_vec2d;

typedef struct s_player
{
	t_vec2d		pos;
	t_vec2d		dir;
	t_vec2d		camera_plane;
}				t_player;

typedef struct s_rgb
{
	int			red;
	int			green;
	int			blue;
}				t_rgb;

typedef struct s_textures
{
	char		*north_texture_path;
	char		*south_texture_path;
	char		*west_texture_path;
	char		*east_texture_path;
    void		*north_texture;
	void		*south_texture;
	void		*west_texture;
	void		*east_texture;
	t_rgb		f_rgb;
	t_rgb		c_rgb;
}				t_textures;

typedef struct s_map
{
	char		**grid;
	// char **dfs_map;
	int			row;
	int			column;
}				t_map;

typedef struct s_mgr
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	// t_pos 	player_pos;
	// t_pos 	exit_pos;
	t_textures	*textures;
	// t_char_counters char_counters;
	// int collect_flag;
	// int move_count;
}				t_mgr;

// FUNCTION

int				ft_event_handler(int keycode, t_mgr *mgr);
int				ft_close(t_mgr *mgr);
int				ft_error_message_handler(char *message);
int				is_valid_char(char c);
char			**read_cub_file(t_mgr *mgr, char *map_filepath);
int				count_rows(t_mgr *mgr, char *map_filepath);
void ft_set_xpmfile(t_mgr *mgr);

#endif