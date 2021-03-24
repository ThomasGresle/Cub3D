#include "cub3d.h"

void	malloc_c(t_list *options, char *line)
{
	int	i;

	i = 0;
	if (!(options->ceiling_color = (char *)malloc(sizeof(char) * ft_strlen_parsing(line))))
		return ;
	ft_strcpy_numbers(options->ceiling_color, line);
}

void	malloc_f(t_list *options, char *line)
{
	int	i;

	i = 0;
	if (!(options->floor_color = (char *)malloc(sizeof(char) * ft_strlen_parsing(line))))
		return ;
	ft_strcpy_numbers(options->floor_color, line);
}

void	malloc_sprite(t_list *options, char *line)
{
	int	i;

	i = 0;
	if (!(options->sprite_t = (char *)malloc(sizeof(char) * ft_strlen_parsing(line))))
		return ;
	ft_strcpy_parsing(options->sprite_t, line);
}

void	malloc_r(t_list *options, char *line)
{
	int	i;

	i = 0;
	if (!(options->resolution = (char *)malloc(sizeof(char) * ft_strlen_parsing(line))))
		return ;
	ft_strcpy_numbers(options->resolution, line);
}
