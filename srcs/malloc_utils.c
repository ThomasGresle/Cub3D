#include "../includes/cub3d.h"

void	malloc_string_struct(t_list *options, char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] && line[i][0] && line[i][0] == 'C')
			malloc_c(options, line[i]);
		if (line[i] && line[i][0] && line[i][0] == 'F')
			malloc_f(options, line[i]);
		if (line[i] && line[i][0] && line[i][0] == 'N')
			malloc_n(options, line[i]);
		if (line[i] && line[i][0] && line[i][1]
			&& line[i][0] == 'S' && line[i][1] == 'O')
			malloc_s(options, line[i]);
		if (line[i] && line[i][0] && line[i][0] == 'E')
			malloc_e(options, line[i]);
		if (line[i] && line[i][0] && line[i][0] == 'W')
			malloc_w(options, line[i]);
		i++;
	}
}

void	free_array(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i])
		i++;
	while (i > 0)
	{
		free((*array)[i]);
		i--;
	}
	free((*array)[i]);
	free(*array);
}
