#include "cub3d.h"

int main(int argc, char **argv)
{
    char    **map;
    t_list	options_map;
	int		i;

    map = NULL;
	i = 0;
	if (check_and_parse(argc, argv, &map, &options_map) == 0)
		return (0);
    /* printf("%s\n", options_map.north_t);
    printf("%s\n", options_map.south_t);
    printf("%s\n", options_map.west_t);
    printf("%s\n", options_map.east_t);
    printf("%s\n", options_map.sprite_t);
    printf("%s\n", options_map.resolution);
    printf("%s\n", options_map.floor_color);
    printf("%s\n", options_map.ceiling_color); */
	printf("%d\n", options_map.player_line);
	printf("%d\n", options_map.player_column);
	printf("%c\n", options_map.player_orientation);
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
    return (0);
}
