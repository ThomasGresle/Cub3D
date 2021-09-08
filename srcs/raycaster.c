#include "../includes/cub3d.h"

int	final_raycasting(t_list *config)
{
	config->x = 0;
	set_player(config);
	while (config->x < config->width)
	{
		struct_init2(config);
		step_and_sideDist(config);
		check_hit(config, config->map);
		distance_and_lines(config, config->map);
		init_draw(config, config->map);
		config->x++;
	}
	mlx_put_image_to_window(config->data.mlx_ptr, config->data.mlx_win, config->data.img, 0, 0);
	move_forward_or_back(config, config->map);
	move_right_or_left(config, config->map);
	rotation_right(config);
	rotation_left(config);
	switch_images(config);
	return (0);
}