#include "cub3d.h"

void	malloc_c(t_list *options, char *line)
{
	int	i;

	i = 0;
	if (!(options->ceiling_colour = (char *)malloc(sizeof(char) * ft_strlen_parsing(line))))
		return ;
	ft_strcpy_numbers(options->ceiling_colour, line);
}

void	malloc_f(t_list *options, char *line)
{
	int	i;

	i = 0;
	if (!(options->flour_colour = (char *)malloc(sizeof(char) * ft_strlen_parsing(line))))
		return ;
	ft_strcpy_numbers(options->flour_colour, line);
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
