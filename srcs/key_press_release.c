#include "../includes/cub3d.h"

int	release_keyboard(int keycode, t_list *config)
{
	if (keycode == FORWARD)
		config->data.forward = 0;
	else if (keycode == BACK)
		config->data.back = 0;
	else if (keycode == LEFT)
		config->data.left = 0;
	else if (keycode == RIGHT)
		config->data.right = 0;
	else if (keycode == ROTATE_LEFT)
		config->data.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		config->data.rotate_right = 0;
	return (1);
}

int	press_keyboard(int keycode, t_list *config)
{
	if (keycode == FORWARD)
		config->data.forward = 1;
	else if (keycode == BACK)
		config->data.back = 1;
	else if (keycode == LEFT)
		config->data.left = 1;
	else if (keycode == RIGHT)
		config->data.right = 1;
	else if (keycode == ROTATE_LEFT)
		config->data.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		config->data.rotate_right = 1;
	else if (keycode == 65307)
		free_str_and_map(config, config->map);
	return (1);
}
