#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    t_list	config;
	int		i;

    config.map = NULL;
	i = 0;
	struct_init(&config);
	if (check_and_parse(argc, argv, &config.map, &config) == 0)
	{
		free_str_and_map(&config, config.map);
		return (0);
	}
	printf("1\n");
	init_mlx(&config, config.map);
	free_str_and_map(&config, config.map);
    return (0);
}
