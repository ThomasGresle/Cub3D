#include "../includes/cub3d.h"

void	adapt_string(char *str, char *tmp, int *j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != ' ')
		{
			tmp[(*j)] = str[i];
			i++;
			(*j)++;
		}
		i++;
	}
	tmp[(*j)] = '\0';
	free(str);
	str = NULL;
}

int		atoi_color(char *str, int *i)
{
	int color;

	color = 0;
	while (str[(*i)] && str[(*i)] != ' ')
	{
		color = (color * 10) + (str[(*i)] - 48);
		(*i)++;
	}
	return (color);
}

int		final_color(t_list *config, char *str)
{
	int	color;
	int	i;

	color = 0;
	i = 0;
	color = atoi_color(str, &i) * 65536;
	i++;
	color += atoi_color(str, &i) * 256;
	i++;
	color += atoi_color(str, &i);
	free(str);
	str = NULL;
	return (color);
}
