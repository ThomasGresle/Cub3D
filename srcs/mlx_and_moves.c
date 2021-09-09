#include "../includes/cub3d.h"

int		release_keyboard(int keycode, t_list *config)
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

int		press_keyboard(int keycode, t_list *config)
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
	return (1);
}

void	switch_images(t_list *config)
{
	void	*tmp;

	tmp = config->data.img;
	config->data.img = config->data.img2;
	config->data.img2 = tmp;
	tmp = config->data.addr;
	config->data.addr = config->data.addr2;
	config->data.addr2 = tmp;
}

void	init_mlx(t_list *config, char **map)
{
	set_player(config);
	if (!(config->data.mlx_ptr = mlx_init()))
	{
		printf("Error\nLa mlx ne se lance pas");
		free_str_and_map(config, map);
		return ;
	}
	config->texerror = 0;
	get_and_check_texture(config);
	if (config->texerror == 0)
	{
		config->data.img = mlx_new_image(config->data.mlx_ptr, config->width, config->height);
		config->data.addr = (int *)mlx_get_data_addr(config->data.img, &config->data.bits_per_pixel,
							&config->data.line_length, &config->data.endian);
		config->data.mlx_win = mlx_new_window(config->data.mlx_ptr, config->width, config->height, "Raycasting cub3d");
		config->data.img2 = mlx_new_image(config->data.mlx_ptr, config->width, config->height);
		config->data.addr2 = (int *)mlx_get_data_addr(config->data.img2, &config->data.bits_per_pixel,
							&config->data.line_length, &config->data.endian);
		mlx_hook(config->data.mlx_win, 33, 1L << 17, clear_mlx, config);
		mlx_hook(config->data.mlx_win, 2, 1L << 0, press_keyboard, config);
		mlx_loop_hook(config->data.mlx_ptr, final_raycasting, config);
		mlx_hook(config->data.mlx_win, 3, 1L << 1, release_keyboard, config);
		mlx_loop(config->data.mlx_ptr);
	}
}