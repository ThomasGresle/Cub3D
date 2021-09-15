#include "../includes/cub3d.h"

void	error_msg(int i, int j, t_list *config)
{
	printf("Error\nLa map est ouverte au niveau de la %de ligne, %de colonne\n",
		i + 1, j + 1);
	config->error = 1;
}

void	check_walls(char **map, int *i, int *j, t_list *config)
{
	int	k;

	k = 0;
	go_on_top_right(map, i, j, &(*config));
	while (config->error == 0 && k < 10)
	{
		check_right(map, i, j, &(*config));
		if (config->error == 0)
			check_bottom(map, i, j, &(*config));
		if (config->error == 0)
			check_left(map, i, j, &(*config));
		if (config->error == 0)
			check_top(map, i, j, &(*config));
		k++;
	}
}

void	go_on_top_right(char **map, int *i, int *j, t_list *config)
{
	while (config->error == 0 && map[(*i)] && map[(*i) - 1]
			&& map[(*i)][(*j)] && map[(*i) - 1][(*j)]
			&& map[(*i)][(*j) + 1] && (map[(*i) - 1][(*j)] != '1'
			&& map[(*i)][(*j) + 1] != '1'))
	{
		(*i)--;
		if (map[(*i)] && map[(*i)][(*j)] && (!map[(*i) - 1] || !(map[(*i) - 1][(*j)])))
			error_msg(*i - 1, *j, &(*config));
		if (map[(*i) - 1] && map[(*i) - 1][(*j)] == '1')
		{
			while (map[(*i)][(*j)] && map[(*i)][(*j) + 1]
			&& map[(*i)][(*j) + 1] == '0' && map[(*i) - 1][(*j)]
			&& map[(*i) - 1][(*j)] == '1')
				(*j)++;
			if (!(map[(*i)][(*j) + 1]))
				error_msg(*i, *j + 1, &(*config));
		}
	}
}

void	check_inside_map(char **map, t_list *config)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < config->line_nbr && map[i][j] && config->error == 0)
	{
		while (map[i][j] && config->error == 0)
		{
			if (map[i][j] != '0' && map[i][j] != '1'
			&& map[i][j] != 'E' && map[i][j] != 'W'
			&& map[i][j] != ' ' && map[i][j] != 'S' && map[i][j] != 'N')
			{
				printf("Error\nCaractere incorrect dans la map:");
				printf("%c a la %de ligne %de colonne\n",
					map[i][j], i + 1, j + 1);
				config->error = 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_check_file(char *file)
{
	int	fd;

	fd = 0;
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		printf("Error\nLe fichier est un dossier\n");
		return (0);
	}
	if (fd > 0)
		close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nLe fichier est invalide\n");
		return (0);
	}
	if (fd > 0)
		close(fd);
	return (1);
}
