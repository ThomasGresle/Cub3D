#include "../includes/cub3d.h"

void	move_forward_or_back(t_list *config, char **map)
{
	if (config->data.forward == 1)
	{
		if (map[(int)(config->posX + (config->dirX * config->movespeed * 2))][(int)config->posY] == '0')
			config->posX += config->dirX * config->movespeed;
		if (map[(int)(config->posX)][(int)(config->posY + (config->dirY * config->movespeed * 2))] == '0')
			config->posY += config->dirY * config->movespeed;
	}
	if (config->data.back == 1)
	{
		if (map[(int)(config->posX - (config->dirX * config->movespeed * 2))][(int)(config->posY)] == '0')
			config->posX -= config->dirX * config->movespeed;
		if (map[(int)(config->posX)][(int)(config->posY - (config->dirY * config->movespeed * 2))] == '0')
			config->posY -= config->dirY * config->movespeed;
	}
}

void	move_right_or_left(t_list *config, char **map)
{
	if (config->data.right == 1)
	{
		if (map[(int)(config->posX + config->dirY * (config->movespeed * 2))][(int)config->posY] == '0')
			config->posX += config->dirY * config->movespeed;
		if (map[(int)config->posX][(int)(config->posY - config->dirX * (config->movespeed * 2))] == '0')
			config->posY -= config->dirX * config->movespeed;
	}
	if (config->data.left == 1)
	{
		if (map[(int)(config->posX - config->dirY * (config->movespeed * 2))][(int)config->posY] == '0')
			config->posX -= config->dirY * config->movespeed;
		if (map[(int)config->posX][(int)(config->posY + config->dirX * (config->movespeed * 2))] == '0')
			config->posY += config->dirX * config->movespeed;
	}
}

void	rotation_right(t_list *config)
{
	double	oldplaneX;
	double	olddirX;

	oldplaneX = config->planeX;
	olddirX = config->dirX;
	if (config->data.rotate_right == 1)
	{
		config->dirX = config->dirX * cos(-config->rotspeed / 2) - config->dirY * sin(-config->rotspeed / 2);
		config->dirY = olddirX * sin(-config->rotspeed / 2) + config->dirY * cos(-config->rotspeed / 2);
		config->planeX = config->planeX * cos(-config->rotspeed / 2) - config->planeY * sin(-config->rotspeed / 2);
		config->planeY = oldplaneX * sin(-config->rotspeed / 2) + config->planeY * cos(-config->rotspeed / 2);
	}
}

void	rotation_left(t_list *config)
{
	double	oldplaneX;
	double	olddirX;

	oldplaneX = config->planeX;
	olddirX = config->dirX;
	if (config->data.rotate_left == 1)
	{
		config->dirX = config->dirX * cos(config->rotspeed / 2) - config->dirY * sin(config->rotspeed / 2);
		config->dirY = olddirX * sin(config->rotspeed / 2) + config->dirY * cos(config->rotspeed / 2);
		config->planeX = config->planeX * cos(config->rotspeed / 2) - config->planeY * sin(config->rotspeed / 2);
		config->planeY = oldplaneX * sin(config->rotspeed / 2) + config->planeY * cos(config->rotspeed / 2);
	}
}