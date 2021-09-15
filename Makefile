NAME		=	cub3D

HEADER		=	./includes/

MLX			=	mlx/libmlx.a

MLX_LINUX	=	-lm -lbsd -lX11 -lXext

CC			=	clang

FLAGS		=	-g -Werror -Wall -Wextra -I $(HEADER)

SRCS		=	srcs/cub3d.c \
			srcs/ceiling_and_floor.c \
			srcs/check_errors_utils.c \
			srcs/check_errors.c \
			srcs/check_map_utils.c \
			srcs/check_walls_utils.c \
			srcs/ft_atoi.c \
			srcs/ft_free.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \
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
			srcs/mlx_utils.c \
			srcs/copy_utils_norm.c \
			srcs/struct_init.c \
			srcs/dda.c\
			srcs/text_utils.c\
			srcs/check_file.c\
			srcs/check_file_utils.c\
			srcs/check_file_utils2.c\
			srcs/check_file_norm.c \

OBJS		=	$(SRCS:.c=.o)

.c.o		:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all		:	$(NAME)

$(NAME)		:	$(OBJS) $(LIBFT) $(MLX) $(HEADER) map.cub
			$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(MLX) $(MLX_LINUX)

$(MLX)		:
			make -C ./mlx

clean		:
			rm -rf $(OBJS)
			make clean -C ./mlx

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all
