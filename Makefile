NAME		=	cub3d

HEADER		=	./includes/

MLX			=	mlx/libmlx.a

MLX_LINUX	=	-lm -lbsd -lX11 -lXext

CC			=	gcc

FLAGS		=	-Werror -Wall -Wextra -I $(HEADER)

SRCS		=	srcs/cub3d.c \
			srcs/ceiling_and_floor.c \
			srcs/check_errors_utils.c \
			srcs/check_errors.c \
			srcs/check_map_utils.c \
			srcs/check_walls_utils.c \
			srcs/ft_atoi.c \
			srcs/ft_free.c \
			srcs/get_next_line_utils.c \
			srcs/get_next_line.c \
			srcs/malloc_utils.c \
			srcs/mlx_and_moves.c \
			srcs/moves.c \
			srcs/parsing_map_utils.c \
			srcs/parsing_utils.c \
			srcs/parsing.c \
			srcs/raycaster.c \
			srcs/set_player.c \
			srcs/struct_config.c \
			srcs/struct_walls.c \

OBJS		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)		:	$(OBJS) $(LIBFT) $(MLX) $(HEADER) map.cub
			$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX) $(MLX_LINUX)

$(MLX)		:
			make -C ./mlx

clean		:
			rm -rf $(OBJS)
			make clean -C ./mlx

fclean		:	clean
			rm $(NAME)

re		:	fclean all