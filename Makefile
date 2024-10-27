NAME     = cub3D
CC       = cc
CFLAGS   = $(INCLUDES)
# CFLAGS   = $(INCLUDES) -g -fsanitize=address
# CFLAGS   = -Wall -Wextra -Werror $(INCLUDES)
INCLUDES = -I $(LIBFT_DIR)/include -I $(MLX_DIR) -I include
LIB = -L $(MLX_DIR) -l $(MLX) -L $(LIBFT_DIR) -l $(LIBFT) \
	-L/usr/X11R6/lib -lX11 -lXext
SRC_DIR = ./src

LIBFT = ft
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux
MLX = mlx_Darwin

SRCS     = $(SRC_DIR)/main.c $(SRC_DIR)/event.c
OBJS     = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
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

re: fclean all

.PHONY: all clean fclean re