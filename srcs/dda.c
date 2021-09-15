/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:13:29 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/15 19:13:30 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_hit(t_list *config, char **map)
{
	while (config->hit == 0)
	{
		if (config->sidedistx < config->sidedisty)
		{
			config->sidedistx += config->deltadistx;
			config->mapx += config->stepx;
			config->side = 0;
		}
		else
		{
			config->sidedisty += config->deltadisty;
			config->mapy += config->stepy;
			config->side = 1;
		}
		if (map[config->mapx][config->mapy] == '1')
			config->hit = 1;
	}
}

void	distance_and_lines(t_list *config)
{
	if (config->side == 0)
		config->perpwalldist = (config->mapx - config->posx
				+ (1 - config->stepx) / 2) / config->raydirx;
	else
		config->perpwalldist = (config->mapy - config->posy
				+ (1 - config->stepy) / 2) / config->raydiry;
	config->lineheight = (int)(config->height / config->perpwalldist);
	config->drawstart = -config->lineheight / 2 + config->height / 2;
	if (config->drawstart < 0)
		config->drawstart = 0;
	config->drawend = config->lineheight / 2 + config->height / 2;
	if (config->drawend >= config->height)
		config->drawend = config->height - 1;
}

void	init_draw(t_list *config)
{
	int	i;
	int	j;

	config->drawend = config->height - config->drawstart;
	i = config->drawend;
	j = -1;
	while (++j < config->drawstart)
		config->data.addr[j * config->data.line_length / 4
			+ config->x] = config->final_ceiling;
	if (j <= config->drawend)
		draw_text(config, config->x, j);
	j = i;
	while (++j < config->height)
		config->data.addr[j * config->data.line_length / 4
			+ config->x] = config->final_floor;
}

void	draw_text(t_list *config, int x, int y)
{
	y = config->drawstart - 1;
	choice_texture(config);
	config->step = 1.0 * config->texture[0].height / config->lineheight;
	texture_calculation(config);
	config->texpos = (config->drawstart - config->height / 2
			+ config->lineheight / 2) * config->step;
	while (++y <= config->drawend)
	{
		config->texy = (int)config->texpos
			& (config->texture[config->texnum].height - 1);
		config->texpos += config->step;
		if (y < config->height && x < config->width)
			config->data.addr[y * config->data.line_length / 4 + x]
				= config->texture[config->texnum].addr[config->texy
				* config->texture[config->texnum].line_length / 4
				+ config->texx];
	}
}
