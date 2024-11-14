NAME     = cub3D
CC       = cc
# CFLAGS   = $(INCLUDES)
CFLAGS   = $(INCLUDES) -g -fsanitize=address
# CFLAGS   = -Wall -Wextra -Werror $(INCLUDES)
INCLUDES = -I $(LIBFT_DIR)/include -I $(MLX_DIR) -I include
LIB = -L $(MLX_DIR) -l $(MLX) -L $(LIBFT_DIR) -l $(LIBFT) \
	-L/usr/X11R6/lib -lX11 -lXext
SRC_DIR = ./src

LIBFT = ft
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux
MLX = mlx_Darwin

SRCS     = $(SRC_DIR)/main.c $(SRC_DIR)/event/event.c $(SRC_DIR)/error/error.c $(SRC_DIR)/parse/readfile.c $(SRC_DIR)/utils.c \
		$(SRC_DIR)/dda/dda.c $(SRC_DIR)/render/rendering.c $(SRC_DIR)/render/floor.c $(SRC_DIR)/parse/init_texture.c \
		$(SRC_DIR)/event/event2.c $(SRC_DIR)/parse/init_player.c $(SRC_DIR)/parse/map_check.c $(SRC_DIR)/render/render_utils.c \
		$(SRC_DIR)/validate/ft_strtol.c $(SRC_DIR)/validate/ft_strtol_utils.c $(SRC_DIR)/validate/validate.c \
		$(SRC_DIR)/validate/validate_figure.c $(SRC_DIR)/validate/validate_map_detail.c $(SRC_DIR)/validate/validate_path.c \
		$(SRC_DIR)/validate/validate_setting.c $(SRC_DIR)/validate/validate_utils.c $(SRC_DIR)/parse/parse_data.c \
		$(SRC_DIR)/utils/xutils.c $(SRC_DIR)/clean/cleanup.c $(SRC_DIR)/parse/init_mgr.c

OBJS     = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	gcc $(CFLAGS) $(OBJS) $(INCLUDE) $(LIB) -framework OpenGL -framework AppKit -o $(NAME)

.c.o: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

re: fclean all

test:
	./cub3D map/valid/map.cub

err00:
	cat map/invalid/invalid_data_00.cub
	./cub3D map/invalid/invalid_data_00.cub

err01:
	cat map/invalid/invalid_data_01.cub
	./cub3D map/invalid/invalid_data_01.cub

err02:
	cat map/invalid/invalid_data_02.cub
	./cub3D map/invalid/invalid_data_02.cub

err03:
	cat map/invalid/invalid_data_03.cub
	./cub3D map/invalid/invalid_data_03.cub

err04:
	cat map/invalid/invalid_data_04.cub
	./cub3D map/invalid/invalid_data_04.cub

err05:
	cat map/invalid/invalid_data_05.cub
	./cub3D map/invalid/invalid_data_05.cub

err06:
	cat map/invalid/invalid_data_06.cub
	./cub3D map/invalid/invalid_data_06.cub

err07:
	cat map/invalid/invalid_data_07.cub
	./cub3D map/invalid/invalid_data_07.cub

err08:
	cat map/invalid/invalid_data_08.cub
	./cub3D map/invalid/invalid_data_08.cub

err09:
	cat map/invalid/invalid_data_09.cub
	./cub3D map/invalid/invalid_data_09.cub

err10:
	cat map/invalid/invalid_data_10.cub
	./cub3D map/invalid/invalid_data_10.cub

err11:
	cat map/invalid/invalid_data_11.cub
	./cub3D map/invalid/invalid_data_11.cub

err12:
	cat map/invalid/invalid_data_12.cub
	./cub3D map/invalid/invalid_data_12.cub

err13:
	cat map/invalid/invalid_data_13.cub
	./cub3D map/invalid/invalid_data_13.cub

.PHONY: all clean fclean re test err00 err01 err02 err03 err04 err05 err06 err07 err08 err09 err10 err11 err12 err13
