#include "cub3d.h"

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

int	line_nbr(char **map, int *error)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			j++;
		}
		i++;
	}
	if (i < 3 || j < 3)
	{
		*error = 1;
		return (0);
	}
	return (1);
}

int	first_line(char **map, int *error)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		
	}
}

int	check_line(char **map, int *error, int *i)
{

}

int	last_line(char **map, int *error, int i)
{

}