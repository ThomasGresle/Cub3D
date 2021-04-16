#include "cub3d.h"


void	error_msg(int i, int j, int *error)
{
	printf("Error\nLa map est ouverte au niveau de la %de ligne, %de colonne", i + 1, j + 1);
	*error = 1;
}

int	check_walls(char **map, int k, int l, int *error)
{
	int i;
	int j;

	i = k;
	j = l;
	go_on_top_right(map, &i, &j, &error);
	if (*error == 0)
		check_top(map, &i, &j, error);

}

int	go_on_top_right(char **map, int *k, int *l, int *error)
{
	int i;
	int j;

	i = *k;
	j = *l;
	while (*error == 0 && map[i] && map[i - 1][j] && map[i - 1][j] != '1')
	{
		i--;
		if (!(map[i - 1][j]))
			error_msg(i, j, error);
		if (map[i - 1][j] == '1')
		{
			while (map[i][j] && map[i][j + 1] && map[i][j + 1] == '0' && map[i - 1] && map[i - 1] == '1')
				j++;
			if (!(map[i][j + 1]))
				error_msg(i, j, error);
		}
	}
}

int	check_top(char **map, int *i, int *j, int *error)
{

}