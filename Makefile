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
           $(SRC_DIR)/event/event2.c $(SRC_DIR)/parse/init_player.c $(SRC_DIR)/parse/map_check.c \
           $(SRC_DIR)/validate/ft_strtol.c $(SRC_DIR)/validate/ft_strtol_utils.c $(SRC_DIR)/validate/validate.c \
           $(SRC_DIR)/validate/validate_data.c $(SRC_DIR)/validate/validate_figure.c $(SRC_DIR)/validate/validate_color.c \
           $(SRC_DIR)/validate/validate_utils.c $(SRC_DIR)/validate/validate_wallpaper.c

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

.PHONY: all clean fclean re
