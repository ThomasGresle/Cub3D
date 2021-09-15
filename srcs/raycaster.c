/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:14:22 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/15 19:14:22 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	final_raycasting(t_list *config)
{
	config->x = 0;
	while (config->x < config->width)
	{
		struct_init2(config);
		step_and_sidedist(config);
		check_hit(config, config->map);
		distance_and_lines(config);
		init_draw(config);
		config->x++;
	}
	mlx_put_image_to_window(config->data.mlx_ptr,
		config->data.mlx_win, config->data.img, 0, 0);
	move_forward_or_back(config, config->map);
	move_right_or_left(config, config->map);
	rotation_right(config);
	rotation_left(config);
	switch_images(config);
	return (0);
}
