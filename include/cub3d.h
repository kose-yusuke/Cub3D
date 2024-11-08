/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:42:28 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/08 12:39:04 by koseki.yusu      ###   ########.fr       */
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

// # define SCREEN_WIDTH 1280
// # define SCREEN_HEIGHT 720
# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 600
# define mapWidth 24
# define mapHeight 24
# define MOVESPEED 0.125
# define ROTSPEED 0.1
# define texWidth 64
# define texHeight 64

// valid char
# define WALL 1
# define SPACE 0
# define PLAYER 'P'
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'
# define X_AXIS 0
# define Y_AXIS 1
# define NORTH_WALL 0
# define SOUTH_WALL 1
# define WEST_WALL 2
# define EAST_WALL 3
# define DIRECTION 4
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
	RIGHT = 100,
	LEFT_VIEW = 65361,
	RIGHT_VIEW = 65363
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

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		camera_x;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	char		ray_mass;
	int			side;
	double		time;
	double		oldTime;
	double		perpWallDist;
	int			hit;
}				t_ray;

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
	t_rgb		f_rgb;
	t_rgb		c_rgb;
	int 		color_ceiling;
	int 		color_floor;
}				t_textures;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct s_xpms
{
	t_img		*north_xpm;
	t_img		*south_xpm;
	t_img		*west_xpm;
	t_img		*east_xpm;
}				t_xpms;

typedef struct s_map
{
	char		**grid;
	int			row;
	int			column;
}				t_map;

typedef struct s_mgr
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_textures	*textures;
	t_img		wall_img[DIRECTION];
	t_img		img;
}				t_mgr;

// FUNCTION

// event
int				ft_event_handler(int keycode, t_mgr *mgr);
int				ft_close(t_mgr *mgr);
// error handling
int				ft_error_message_handler(char *message);
int				is_valid_char(char c);
// read cubfile
char			**read_cub_file(t_mgr *mgr, char *map_filepath);
int				count_rows(t_mgr *mgr, char *map_filepath);
int				count_columns(t_mgr *mgr);
void			ft_set_xpmfile(t_mgr *mgr);
// utils
char			*ft_strndup(char *src, long len);
size_t			ft_strlen_until_newline(const char *str);
double			absolute_value(double value);
// render
int				render_loop(t_mgr *mgr);
void			init_image(t_mgr *mgr);
void			put_pixel_to_image(t_mgr *mgr, int x, int y, int color);
void			castFloorAndCeiling(t_mgr *mgr);
// dda
void			init_ray_direction(t_ray *ray, t_mgr *mgr, int x);
void			set_ray_steps_and_initial_side_distances(t_ray *ray,
					t_mgr *mgr);
void			perform_dda(t_ray *ray, t_mgr *mgr);
// texture
int				decide_draw_texture(t_ray *ray, t_mgr *mgr, int side);
// debug
void			print_grid(t_mgr *mgr);

#endif