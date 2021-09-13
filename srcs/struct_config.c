#include "../includes/cub3d.h"

void	malloc_c(t_list *options, char *line)
{
	int	i;

	i = 0;
	options->ceiling_color = (char *)malloc(sizeof(char)
			* ft_strlen_parsing(line));
	if (!(options->ceiling_color))
		return ;
	ft_strcpy_numbers(options->ceiling_color, line);
}

void	malloc_f(t_list *options, char *line)
{
	int	i;

	i = 0;
	options->floor_color = (char *)malloc(sizeof(char)
			* ft_strlen_parsing(line));
	if (!(options->floor_color))
		return ;
	ft_strcpy_numbers(options->floor_color, line);
}
