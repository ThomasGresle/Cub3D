#include "../includes/cub3d.h"

void	move_forward_or_back(t_list *config, char **map)
{
	if (config->data.forward == 1)
	{
		if (map[(int)(config->posx + (config->dirx * config->movespeed
				* 2))][(int)config->posy] == '0')
			config->posx += config->dirx * config->movespeed;
		if (map[(int)(config->posx)][(int)(config->posy +
			(config->diry * config->movespeed * 2))] == '0')
			config->posy += config->diry * config->movespeed;
	}
	if (config->data.back == 1)
	{
		if (map[(int)(config->posx - (config->dirx * config->movespeed * 2))]
			[(int)(config->posy)] == '0')
			config->posx -= config->dirx * config->movespeed;
		if (map[(int)(config->posx)][(int)(config->posy
			- (config->diry * config->movespeed * 2))] == '0')
			config->posy -= config->diry * config->movespeed;
	}
}

void	move_right_or_left(t_list *config, char **map)
{
	if (config->data.right == 1)
	{
		if (map[(int)(config->posx + config->diry
				* (config->movespeed * 2))][(int)config->posy] == '0')
			config->posx += config->diry * config->movespeed;
		if (map[(int)config->posx][(int)(config->posy
				- config->dirx * (config->movespeed * 2))] == '0')
			config->posy -= config->dirx * config->movespeed;
	}
	if (config->data.left == 1)
	{
		if (map[(int)(config->posx - config->diry
				* (config->movespeed * 2))][(int)config->posy] == '0')
			config->posx -= config->diry * config->movespeed;
		if (map[(int)config->posx][(int)(config->posy + config->dirx
				* (config->movespeed * 2))] == '0')
			config->posy += config->dirx * config->movespeed;
	}
}

void	rotation_right(t_list *config)
{
	double	oldplanex;
	double	olddirx;

	oldplanex = config->planex;
	olddirx = config->dirx;
	if (config->data.rotate_right == 1)
	{
		config->dirx = config->dirx * cos(-config->rotspeed / 2)
			- config->diry * sin(-config->rotspeed / 2);
		config->diry = olddirx * sin(-config->rotspeed / 2)
			+ config->diry * cos(-config->rotspeed / 2);
		config->planex = config->planex * cos(-config->rotspeed / 2)
			- config->planey * sin(-config->rotspeed / 2);
		config->planey = oldplanex * sin(-config->rotspeed / 2)
			+ config->planey * cos(-config->rotspeed / 2);
	}
}

void	rotation_left(t_list *config)
{
	double	oldplanex;
	double	olddirx;

	oldplanex = config->planex;
	olddirx = config->dirx;
	if (config->data.rotate_left == 1)
	{
		config->dirx = config->dirx * cos(config->rotspeed / 2)
			- config->diry * sin(config->rotspeed / 2);
		config->diry = olddirx * sin(config->rotspeed / 2)
			+ config->diry * cos(config->rotspeed / 2);
		config->planex = config->planex * cos(config->rotspeed / 2)
			- config->planey * sin(config->rotspeed / 2);
		config->planey = oldplanex * sin(config->rotspeed / 2)
			+ config->planey * cos(config->rotspeed / 2);
	}
}
