#include "cub3d.h"

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
    if (argc < 2 || argc > 3)
	{
        printf("Error\nLe nombre d'arguments est incorrect\n");
		return (0);
	}
    else if (ft_check_argv(argv) == 0)
    {
		printf("Error\nLe chemin du fichier a parser est incorrect\n");
		return (0);
	}
    else if (argc  == 3 && (ft_strcmp(argv[2], "--save", 0)) == 0)
	{
		printf("Error\nLe 3e argument est incorrect\n");
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

int		ft_check_map(char **line)
{
	int error;
	int i;
	
	error = 0;
	i = 0;
	if (line_nbr(line, &error) == 0)
		printf("Error\nLa map n'est pas assez grande\n");
	if (error == 0 && first_line(line, &error) == 0)
	{
		printf("Error\nLa premiere ligne de la map est incorrecte\n");
		i++;
	}
	if (error == 0 && line[i - 1] && line[i + 1])
	{
		while (line[i])
		{
			if (check_line(line, &error, &i) == 0)
				printf("Error\nLa %de ligne de la map est incorrecte", (i + 1));
			i++;
		}
	}
	if (error == 0 && last_line(line, &error, i) == 0)
		printf("Error\nLa derniere ligne de la map est incorrecte\n");
	return (error);
}

int		check_and_parse(int argc, char **argv, char ***map, t_list *config)
{
	if (ft_check_args(argc, argv) == 0)
		return (0);
    ft_parse_file(argv, &(*map), &(*config));
    if (ft_check_config(config->ceiling_color) == 0)
		return (0);
	if (ft_check_config(config->floor_color) == 0)
		return (0);
	//if (ft_check_map(*map) == 1)
	//	return (0);
	return (1);
}
