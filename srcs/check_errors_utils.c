#include "../includes/cub3d.h"

int	split_config(char *str, int *i)
{
	char	*number;
	int		j;

	j = 0;
	while (str[(*i) + j] && (str[(*i) + j] == '-' || (str[(*i) + j] >= 48 && str[(*i) + j] <= 57)))
		j++;
	if (!(number = malloc(sizeof(char) * j)))
		return (0);
	j = 0;
	while (str[(*i)] && ((str[(*i)] >= 48 && str[(*i)] <= 57) || str[(*i)] == '-'))
	{
		number[j] = str[(*i)];
		(*i)++;
		j++;
	}
	number[j] = '\0';
	(*i)++;
	return (ft_atoi_and_free(number));
}

int	line_nbr(char **map, t_list *config)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
			j++;
		i++;
	}
	if (i < 3 || j < 3)
	{
		config->error = 1;
		return (0);
	}
	return (1);
}

int		check_position(char ***map, t_list *config)
{
	int i;
	int j;
	int position;

	i = 0;
	j = 0;
	position = 0;
	while ((*map)[i] && (*map)[i][j])
	{
		while ((*map)[i][j] && (*map)[i][j] != 'W' && (*map)[i][j] != 'N'
		&& (*map)[i][j] != 'S' && (*map)[i][j] != 'E')
		{
			j++;
		}
		if ((*map)[i][j] && ((*map)[i][j] == 'W' || (*map)[i][j] == 'E'
		|| (*map)[i][j] == 'S' || (*map)[i][j] == 'N'))
		{
			position++;
			config->startx = i;
			config->starty = j;
			config->player_orientation = (*map)[i][j];
			(*map)[i][j] = '0';
			j++;
		}
		if (!((*map)[i][j]))
		{
			i++;
			j = 0;
		}
	}
	if (position != 1)
	{
		printf("Error\nIl y a une erreur concernant la position du joueur dans la map\n");
		return (1);
	}
	return (0);
}