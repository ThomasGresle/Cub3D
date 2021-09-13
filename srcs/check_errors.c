#include "../includes/cub3d.h"

int     ft_check_argv(char **argv)
{
    int i;

    i = 0;
    if (argv[1][0] == '.' || argv[1][0] == '\0')
        return (0);
    while (argv[1][i] && argv[1][i] != '.')
        i++;
    if (argv[1][i] == '\0')
        return (0);
    i++;
    if (ft_strcmp(argv[1], "cub", i))
        return (1);
    return (0);
}

int		ft_check_args(int argc, char **argv)
{
    if (argc != 2)
	{
        printf("Error\nLe nombre d'arguments est incorrect\n");
		return (0);
	}
    else if (ft_check_argv(argv) == 0)
    {
		printf("Error\nLe chemin du fichier a parser est incorrect\n");
		return (0);
	}
	return (1);
}

int		ft_check_config(char *str)
{
	int i;
	int j;
	int number;

	i = 0;
	j = 0;
	number = 0;
	while (j < 3)
	{
		number = split_config(str, &i);
		if (number < 0 || number > 255)
		{
			printf("Error\nLa couleur du plafond ou du sol est incorrecte\n");
			return (0);
		}
		j++;
	}
	return (1);
}

int		ft_check_map(char **line, t_list *config)
{
	int i;
	int j;
	
	i = config->startX;
	j = config->startY;
	if (line_nbr(line, &(*config)) == 0)
		printf("Error\nLa map n'est pas assez grande\n");
	else
		check_inside_map(line, &(*config));
	if (config->error != 1)
		check_walls(line, &i, &j, &(*config));
	return (config->error);
}

int		check_and_parse(int argc, char **argv, char ***map, t_list *config)
{
	if (ft_check_args(argc, argv) == 0)
		return (0);
	if (ft_check_file(argv[1]) == 0)
		return (0);
    ft_parse_file(argv, &(*map), &(*config));
	/* if ((!(config->ceiling_color)) || config->ceiling_color[0] == '\0' ||
		(!(config->floor_color)) || config->floor_color[0] == '\0')
	{
		printf("Error\nLa couleur du sol ou du plafond est incorrecte\n");
		free_str_and_map(config, *map);
	} */
	if (ft_check_config(config->ceiling_color) == 0)
		return (0);
	config->final_ceiling = final_color(config, config->ceiling_color);
	if (ft_check_config(config->floor_color) == 0)
		return (0);
	config->final_floor = final_color(config, config->floor_color);
	if (check_position(&(*map), &(*config)))
		return (0);
	if (ft_check_map(*map, &(*config)))
		return (0);
	return (1);
}
