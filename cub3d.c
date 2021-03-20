#include "cub3d.h"

int main(int argc, char **argv)
{
    char    **map;
    t_list	options_map;

    map = NULL;
    ft_parse_file(argv, map, &options_map);
    ft_check_config(options_map);
    printf("%s\n", options_map.north_t);
    printf("%s\n", options_map.south_t);
    printf("%s\n", options_map.west_t);
    printf("%s\n", options_map.east_t);
    printf("%s\n", options_map.sprite_t);
    printf("%s\n", options_map.resolution);
    printf("%s\n", options_map.flour_colour);
    printf("%s\n", options_map.ceiling_colour);
    return (0);
}
