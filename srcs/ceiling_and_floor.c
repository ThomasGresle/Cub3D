#include "../includes/cub3d.h"

void	adapt_string(char *str, char *tmp, int *j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != ',')
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

void	correct_ceiling(t_list *config, char *str)
{
	int i;
	int	j;
	char *tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	if (!(tmp = malloc(sizeof(char) * 40)))
		return ;
	adapt_string(str, tmp, &j);
	if (!(config->ceiling_color = malloc(sizeof(char) * (j + 1))))
		return ;
	j = 0;
	adapt_string(tmp, config->ceiling_color, &j);
	config->final_ceiling = ft_atoi_and_free(config->ceiling_color);
}

void	correct_floor(t_list *config, char *str)
{
	int i;
	int	j;
	char *tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	if (!(tmp = malloc(sizeof(char) * 40)))
		return ;
	adapt_string(str, tmp, &j);
	if (!(config->floor_color = malloc(sizeof(char) * (j + 1))))
		return ;
	j = 0;
	adapt_string(tmp, config->floor_color, &j);
	config->final_floor = ft_atoi_and_free(config->floor_color);
}
