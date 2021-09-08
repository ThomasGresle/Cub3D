#include "../includes/cub3d.h"

void	ft_malloc_map(char ***map, int i, int j, t_list *config)
{
	int k;

	k = 0;
	config->line_nbr = i - 1;
	config->column_nbr = j - 1;
	if (!(*map = malloc(sizeof(char *) * (i + 1))))
		return ;
	while (k < i)
	{
		if (!((*map)[k] = (char *)malloc(sizeof(char) * (j + 1))))
			return ;
		k++;
	}
	*map[k] = malloc(sizeof(char) * 1);
}

void	copy_line_in_map(char **map, char *str, int l)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			(*map)[i] = '0';
		else
			(*map)[i] = str[i];
		i++;
	}
	while (i < l)
	{
		(*map)[i] = '0';
		i++;
	}
	(*map)[i] = '\0';
}

void	create_map(char ***map, char **line, int i, int l)
{
	int j;

	j = 0;
	while (line [i])
	{
		copy_line_in_map(&((*map)[j]), line[i], l);
		i++;
		j++;
	}
	**map[j] = '\0';
}
