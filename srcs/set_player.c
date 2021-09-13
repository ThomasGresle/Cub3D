#include "../includes/cub3d.h"

void	struct_init2(t_list *config)
{
	config->perpwalldist = 0;
	config->hit = 0;
	config->camerax = 2 * config->x / (double)config->width - 1;
	config->raydirx = config->dirx + config->planex * config->camerax;
	config->raydiry = config->diry + config->planey * config->camerax;
	config->mapx = (int)config->posx;
	config->mapy = (int)config->posy;
	config->movespeed = 0.05;
	config->rotspeed = 0.033 * 1;
	if (config->raydiry == 0)
		config->deltadistx = 0;
	else if (config->raydirx == 0)
		config->deltadistx = 1;
	else
		config->deltadistx = sqrt(1 + (config->raydiry
					* config->raydiry) / (config->raydirx *
				config->raydirx));
	if (config->raydirx == 0)
		config->deltadisty = 0;
	else if (config->raydiry == 0)
		config->deltadisty = 1;
	else
		config->deltadisty = sqrt(1 + (config->raydirx
					* config->raydirx) / (config->raydiry
				* config->raydiry));
}

void	set_player(t_list *config)
{
	config->posx = config->startx + 0.5;
	config->posy = config->starty + 0.5;
	if (config->player_orientation == 'N')
	{
		config->dirx = -1;
		config->planey = 0.66;
	}
	else if (config->player_orientation == 'S')
	{
		config->dirx = 1;
		config->planey = -0.66;
	}
	else if (config->player_orientation == 'E')
	{
		config->diry = 1;
		config->planex = 0.66;
	}
	else
	{
		config->diry = -1;
		config->planex = -0.66;
	}
}

void	step_and_sidedist(t_list *config)
{
	if (config->raydirx < 0)
	{
		config->stepx = -1;
		config->sidedistx = (config->posx - config->mapx)
			* config->deltadistx;
	}
	else
	{
		config->stepx = 1;
		config->sidedistx = (config->mapx + 1.0 - config->posx)
			* config->deltadistx;
	}
	if (config->raydiry < 0)
	{
		config->stepy = -1;
		config->sidedisty = (config->posy - config->mapy)
			* config->deltadisty;
	}
	else
	{
		config->stepy = 1;
		config->sidedisty = (config->mapy + 1.0 - config->posy)
			* config->deltadisty;
	}
}
