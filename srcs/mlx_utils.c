/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:14:01 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/17 17:40:19 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	erreur_mlx_init(t_list *config, char **map)
{
	printf("Error\nLa mlx ne se lance pas");
	free_str_and_map(config);
}
