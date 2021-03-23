#include "cub3d.h"

void	ft_malloc_map(char ***map, int i, int j)
{
	int k;

	k = 0;
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

void	copy_line_in_map(char **map, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 51 && str[i] > 47) || str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			(*map)[i] = str[i];
		if (str[i] == ' ')
			(*map)[i] = '0';
		i++;
	}
	(*map)[i] = '\0';
}

void	create_map(char ***map, char **line, int i)
{
	int j;

	j = 0;
	while (line [i])
	{
		copy_line_in_map(&((*map)[j]), line[i]);
		i++;
		j++;
	}
	**map[j] = '\0';
}
