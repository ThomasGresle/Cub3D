#include "../includes/cub3d.h"

void	struct_init(t_list *config)
{
	config->north_t = NULL;
	config->south_t = NULL;
	config->west_t = NULL;
	config->east_t = NULL;
	config->floor_color = NULL;
	config->final_floor = 0;
	config->ceiling_color = NULL;
	config->final_ceiling = 0;
	config->posx = 0;
	config->posy = 0;
	config->line_nbr = 0;
	config->column_nbr = 0;
	config->error = 0;
	config->time = 0;
	config->old_time = 0;
	config->planex = 0;
	config->planey = 0;
	config->dirx = 0;
	config->diry = 0;
	config->width = 800;
	config->height = 600;
	config->texwidth = 64;
	config->texheight = 64;
	struct_init3(config);
}

void	struct_init3(t_list *config)
{
	config->x = 0;
	config->camerax = 0;
	config->raydirx = 0;
	config->raydiry = 0;
	config->mapx = 0;
	config->mapy = 0;
	config->sidedistx = 0;
	config->sidedisty = 0;
	config->deltadistx = 0;
	config->deltadisty = 0;
	config->stepx = 0;
	config->stepy = 0;
	config->side = 0;
	config->lineheight = 0;
	config->drawstart = 0;
	config->drawend = 0;
	config->texture[0].img = NULL;
	config->texture[1].img = NULL;
	config->texture[2].img = NULL;
	config->texture[3].img = NULL;
	struct_init4(config);
}

void	struct_init4(t_list *config)
{
	config->data.forward = 0;
	config->data.back = 0;
	config->data.left = 0;
	config->data.right = 0;
	config->data.rotate_right = 0;
	config->data.rotate_left = 0;
	config->movespeed = 0;
	config->rotspeed = 0;
	config->texerror = -1;
	config->north = 0;
	config->south = 0;
	config->east = 0;
	config->west = 0;
	config->f = 0;
	config->c = 0;
	config->count = 0;
}

void	init_texture_address(t_list *config)
{
	config->texture[0].addr = (int *)mlx_get_data_addr(config->texture[0].img,
			&config->texture[0].bits_per_pixel,
			&config->texture[0].line_length, &config->texture[0].endian);
	config->texture[1].addr = (int *)mlx_get_data_addr(config->texture[1].img,
			&config->texture[1].bits_per_pixel,
			&config->texture[1].line_length, &config->texture[1].endian);
	config->texture[2].addr = (int *)mlx_get_data_addr(config->texture[2].img,
			&config->texture[2].bits_per_pixel,
			&config->texture[2].line_length, &config->texture[2].endian);
	config->texture[3].addr = (int *)mlx_get_data_addr(config->texture[3].img,
			&config->texture[3].bits_per_pixel,
			&config->texture[3].line_length, &config->texture[3].endian);
}
