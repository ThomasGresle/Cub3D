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

int		ft_check_config(t_list config)
{
	if (config.ceiling_colour)
	return (1);
}

int		ft_check_map(char **line)
{
	int error;

	error = 0;

	return (error);
}

int		check_and_parse(int argc, char **argv, char ***map, t_list *config)
{
	if (ft_check_args(argc, argv) == 0)
		return (0);
    ft_parse_file(argv, &(*map), &(*config));
    if (ft_check_config(*config) == 0)
		return (0);
	return (1);
}
