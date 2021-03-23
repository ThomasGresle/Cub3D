#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef	struct	s_list
{
		char	*resolution;
		char	*north_t;
		char	*south_t;
		char	*west_t;
		char	*east_t;
		char	*sprite_t;
		char	*flour_colour;
		char	*ceiling_colour;
}				t_list;

char		**parse(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			get_next_line(int fd, char **line);
void		ft_copy_file(char **argv, char ***line);
int			ft_check_argv(char **argv);
int			ft_check_args(int argc, char **argv);
int			ft_strcmp(char *s1, char *s2, int j);
void		ft_parse_file(char **argv, char ***map, t_list *options);
void		malloc_string_struct(t_list *options, char **line);
void		malloc_n(t_list *options, char *line);
void		malloc_s(t_list *options, char *line);
void		malloc_e(t_list *options, char *line);
void		malloc_w(t_list *options, char *line);
void		malloc_c(t_list *options, char *line);
void		malloc_f(t_list *options, char *line);
void		malloc_sprite(t_list *options, char *line);
void		malloc_r(t_list *options, char *line);
int 		ft_strlen_parsing(char *str);
void    	ft_strcpy_parsing(char *dest, char *str);
void	    ft_strcpy_numbers(char *dst, char *str);
int			ft_check_config(t_list config);
void		free_array(char ***array);
void		ft_malloc_map(char ***map, int i, int j);
int			ft_check_map(char **line);
void		copy_line_in_map(char **map, char *str);
void		ft_parse_map(char ***map, char **line);
void		create_map(char ***map, char **line, int i);
void		free_array(char ***array);
int			check_and_parse(int argc, char **argv, char ***map, t_list *config);

#endif