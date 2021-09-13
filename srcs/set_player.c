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

void	get_and_check_texture(t_list *config)
{
	if (!(config->texture[0].img = mlx_xpm_file_to_image(config->data.mlx_ptr,
		config->north_t, &(config->texture[0].width),
		&(config->texture[0].height))))
		{
			printf("Error\nTexture nord incorrecte\n");
			config->texerror = 1;
		}
	else if (!(config->texture[1].img = mlx_xpm_file_to_image(config->data.mlx_ptr,
		config->south_t, &(config->texture[1].width),
		&(config->texture[1].height))))
		{
			printf("Error\nTexture sud incorrecte\n");
			config->texerror = 1;
		}
	else if (!(config->texture[2].img = mlx_xpm_file_to_image(config->data.mlx_ptr,
		config->west_t, &(config->texture[2].width),
		&(config->texture[2].height))))
		{
			printf("Error\nTexture ouest incorrecte\n");
			config->texerror = 1;
		}
	else if (!(config->texture[3].img = mlx_xpm_file_to_image(config->data.mlx_ptr,
		config->east_t, &(config->texture[3].width),
		&(config->texture[3].height))))
		{
			printf("Error\nTexture est incorrecte\n");
			config->texerror = 1;
		}
	else 
		init_texture_address(config);
}

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
		config->deltadisty = sqrt(1 + (config->raydirx *
			config->raydirx) / (config->raydiry *
			config->raydiry));
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

void	distance_and_lines(t_list *config, char **map)
{
	if (config->side == 0)
		config->perpwalldist = (config->mapx - config->posx +
		(1 - config->stepx) / 2) / config->raydirx;
	else
		config->perpwalldist = (config->mapy - config->posy +
		(1 - config->stepy) / 2) / config->raydiry;
	config->lineheight = (int)(config->height / config->perpwalldist);
	config->drawstart = -config->lineheight / 2 + config->height / 2;
	if (config->drawstart < 0)
		config->drawstart = 0;
	config->drawend = config->lineheight / 2 + config->height / 2;
	if (config->drawend >= config->height)
		config->drawend = config->height - 1;
}

void	choice_texture(t_list *config, char **map)
{
	if (config->side == 0 && config->raydirx < 0)
		config->texnum = 0;
	if (config->side == 0 && config->raydirx >= 0)
		config->texnum = 1;
	if (config->side == 1 && config->raydiry < 0)
		config->texnum = 2;
	if (config->side == 1 && config->raydiry >= 0)
		config->texnum = 3;
}

void	texture_calculation(t_list *config, char **map)
{
	if (config->side == 0)
		config->wallx = config->posy + config->perpwalldist * config->raydiry;
	else
		config->wallx = config->posx + config->perpwalldist * config->raydirx;
	config->wallx -= floor(config->wallx);
	config->texx = (int)(config->wallx * (double)config->texture[config->texnum].width);
	if (config->side == 0 && config->raydirx > 0)
		config->texx = config->texture[config->texnum].width - config->texx - 1;
	if (config->side == 1 && config->raydiry < 0)
		config->texx = config->texture[config->texnum].width - config->texx - 1;
}

void	init_draw(t_list *config, char **map)
{
	int	i;
	int	j;

	config->drawend = config->height - config->drawstart;

	i = config->drawend;
	j = -1;
	while (++j < config->drawstart)
		config->data.addr[j * config->data.line_length / 4 + config->x] = config->final_ceiling;
	if (j <= config->drawend)
		draw_text(config, map, config->x, j);
	j = i;
	while (++j < config->height)
		config->data.addr[j * config->data.line_length / 4 + config->x] = config->final_floor;
}

void	draw_text(t_list *config, char **map, int x, int y)
{
	y = config->drawstart - 1;
	choice_texture(config, map);
	config->step = 1.0 * config->texture[0].height / config->lineheight;
	texture_calculation(config, map);
	config->texpos = (config->drawstart - config->height / 2 +
		config->lineheight / 2) * config->step;
	while (++y <= config->drawend)
	{
		config->texy = (int)config->texpos & (config->texture[config->texnum].height - 1);
		config->texpos += config->step;
		if (y < config->height && x < config->width)
			config->data.addr[y * config->data.line_length / 4 + x] = 
			config->texture[config->texnum].addr[config->texy * config->texture[config->texnum].line_length / 4 + config->texx];
	}
}