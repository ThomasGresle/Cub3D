#include "../includes/cub3d.h"

void	malloc_n(t_list *options, char *line)
{
	int	i;

	i = 0;
	if (!(options->north_t = (char *)malloc(sizeof(char) * ft_strlen_parsing(line))))
		return ;
	ft_strcpy_parsing(options->north_t, line);
}

void	malloc_s(t_list *options, char *line)
{
	int	i;

	i = 0;
	if (!(options->south_t = (char *)malloc(sizeof(char) * ft_strlen_parsing(line))))
		return ;
	ft_strcpy_parsing(options->south_t, line);
}

void	malloc_e(t_list *options, char *line)
{
	int	i;

	i = 0;
	if (!(options->east_t = (char *)malloc(sizeof(char) * ft_strlen_parsing(line))))
		return ;
	ft_strcpy_parsing(options->east_t, line);
}

void	malloc_w(t_list *options, char *line)
{
	int	i;

	i = 0;
	if (!(options->west_t = (char *)malloc(sizeof(char) * ft_strlen_parsing(line))))
		return ;
	ft_strcpy_parsing(options->west_t, line);
}
