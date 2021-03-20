#include "cub3d.h"

int     ft_check_args(int argc, char **argv)
{
    int result;

    result = 0;
    if (argc < 2 || argc > 3)
        printf("Error\nLe nombre d'arguments est incorrect\n");
    else
    {
        result = ft_check_argv(argv);
        if (result == 1 && argc  == 3)
            result = ft_strcmp(argv[2], "--save", 0);
    }
    return (result);
}

void    ft_check_config()
{
    
}