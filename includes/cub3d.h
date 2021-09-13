#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include "../mlx/mlx.h"

# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define FORWARD		119
# define BACK			115
# define RIGHT			100
# define LEFT			97

typedef struct s_data {
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		forward;
	int		back;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
	int		width;
	int		height;
	void	*img2;
	int		*addr2;
}				t_data;

typedef struct s_list
{
	char	**map;
	char	*north_t;
	char	*south_t;
	char	*west_t;
	char	*east_t;
	char	*floor_color;
	int		final_floor;
	char	*ceiling_color;
	int		final_ceiling;
	double	posx;
	double	posy;
	char	player_orientation;
	int		startx;
	int		starty;
	int		line_nbr;
	int		column_nbr;
	int		error;
	int		texerror;
	double	time;
	double	old_time;
	double	planex;
	double	planey;
	double	dirx;
	double	diry;
	int		width;
	int		height;
	int		texwidth;
	int		texheight;
	int		x;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	t_data	texture[4];
	t_data	data;
	int		texnum;
	double	wallx;
	int		texx;
	int		texy;
	double	step;
	double	texpos;
	double	movespeed;
	double	rotspeed;
}				t_list;

void		erreur_mlx_init(t_list *config, char **map);
int			ft_check_file(char *file);
char		**parse(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			get_next_line(int fd, char **line);
void		ft_copy_file(char **argv, char ***line, int *error);
int			ft_check_argv(char **argv);
int			ft_check_args(int argc, char **argv);
int			ft_strcmp(char *s1, char *s2, int j);
int			ft_parse_file(char **argv, char ***map, t_list *options);
void		malloc_string_struct(t_list *options, char **line);
void		malloc_n(t_list *options, char *line);
void		malloc_s(t_list *options, char *line);
void		malloc_e(t_list *options, char *line);
void		malloc_w(t_list *options, char *line);
void		malloc_c(t_list *options, char *line);
void		malloc_f(t_list *options, char *line);
int			ft_strlen_parsing(char *str);
void		ft_strcpy_parsing(char *dest, char *str);
void		ft_strcpy_numbers(char *dst, char *str);
int			ft_check_config(char *str);
void		free_array(char ***array);
void		ft_malloc_map(char ***map, int i, int j, t_list *config);
int			ft_check_map(char **line, t_list *config);
void		copy_line_in_map(char **map, char *str, int i);
void		ft_parse_map(char ***map, char **line, t_list *config);
void		create_map(char ***map, char **line, int i, int j);
void		free_array(char ***array);
int			check_and_parse(int argc, char **argv, char ***map, t_list *config);
int			ft_atoi_and_free(char *str);
int			split_config(char *str, int *i);
int			line_nbr(char **map, t_list *config);
void		go_on_top_right(char **map, int *i, int *j, t_list *config);
void		check_walls(char **map, int *i, int *j, t_list *config);
void		error_msg(int i, int j, t_list *config);
void		check_right(char **map, int *i, int *j, t_list *config);
void		check_top(char **map, int *i, int *j, t_list *config);
void		check_left(char **map, int *i, int *j, t_list *config);
void		check_bottom(char **map, int *i, int *j, t_list *config);
int			check_position(char ***map, t_list *config);
void		check_inside_map(char **map, t_list *config);
void		set_player(t_list *config);
void		struct_init(t_list *config);
void		struct_init2(t_list *config);
void		struct_init3(t_list *config);
void		struct_init4(t_list *config);
void		step_and_sideDist(t_list *config);
void		check_hit(t_list *config, char **map);
void		distance_and_lines(t_list *config, char **map);
int			final_raycasting(t_list *config);
void		init_texture_adress(t_list *config);
void		get_and_check_texture(t_list *config);
void		free_str_and_map(t_list	*config, char **map);
void		init_mlx(t_list *config, char **map);
int			clear_mlx(t_list *config);
void		free_str_and_map(t_list	*config, char **map);
void		init_draw(t_list *config, char **map);
void		switch_images(t_list *config);
void		move_forward_or_back(t_list *config, char **map);
void		move_right_or_left(t_list *config, char **map);
void		rotation_right(t_list *config);
void		rotation_left(t_list *config);
void		draw_text(t_list *config, char **map, int x, int y);
int			final_color(t_list *config, char *str);

#endif