#include "../includes/cub3d.h"

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
	if (str[i] == '\0')
	{
		printf("Error\nIl manque un nombre dans les couleurs du sol ou du plafond\n");
		free(str);
		free_str_and_map(config, config->map);
	}
	color = atoi_color(str, &i) * 65536;
	i++;
	if (str[i] == '\0')
	{
		printf("Error\nIl manque un nombre dans les couleurs du sol ou du plafond\n");
		free(str);
		free_str_and_map(config, config->map);
	}
	color += atoi_color(str, &i) * 256;
	i++;
	if (str[i] == '\0')
	{
		printf("Error\nIl manque un nombre dans les couleurs du sol ou du plafond\n");
		free(str);
		free_str_and_map(config, config->map);
	}
	color += atoi_color(str, &i);
	free(str);
	str = NULL;
	return (color);
}
