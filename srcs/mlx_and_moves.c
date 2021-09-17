/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_and_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:13:56 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/17 17:42:27 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		free_str_and_map(config);
	return (1);
}

void	mlx_on(t_list *config)
{
	mlx_hook(config->data.mlx_win, 33, 1L << 17, free_str_and_map, config);
	mlx_hook(config->data.mlx_win, 2, 1L << 0, press_keyboard, config);
	mlx_hook(config->data.mlx_win, 3, 1L << 1, release_keyboard, config);
	mlx_loop_hook(config->data.mlx_ptr, final_raycasting, config);
	mlx_loop(config->data.mlx_ptr);
}

void	init_mlx(t_list *config, char **map)
{
	set_player(config);
	config->data.mlx_ptr = mlx_init();
	if (!(config->data.mlx_ptr))
		erreur_mlx_init(config, map);
	config->texerror = 0;
	get_and_check_texture(config);
	if (config->texerror == 0)
	{
		config->data.img = mlx_new_image(config->data.mlx_ptr,
				config->width, config->height);
		config->data.addr = (int *)mlx_get_data_addr(config->data.img,
				&config->data.bits_per_pixel,
				&config->data.line_length, &config->data.endian);
		config->data.mlx_win = mlx_new_window(config->data.mlx_ptr,
				config->width, config->height, "Raycasting cub3d");
		config->data.img2 = mlx_new_image(config->data.mlx_ptr,
				config->width, config->height);
		config->data.addr2 = (int *)mlx_get_data_addr(config->data.img2,
				&config->data.bits_per_pixel,
				&config->data.line_length, &config->data.endian);
		mlx_on(config);
	}
}
