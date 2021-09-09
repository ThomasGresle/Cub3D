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
	config->posX = 0;
	config->posY = 0;
	config->line_nbr = 0;
	config->column_nbr = 0;
	config->error = 0;
	config->time = 0;
	config->old_time = 0;
	config->planeX = 0;
	config->planeY = 0;
	config->dirX = 0;
	config->dirY = 0;
	config->width = 640;
	config->height = 480;
	config->texWidth = 64;
	config->texHeight = 64;
	struct_init3(config);
}

void	struct_init3(t_list *config)
{
	config->x = 0;
	config->cameraX = 0;
	config->rayDirX = 0;
	config->rayDirY = 0;
	config->mapX = 0;
	config->mapY = 0;
	config->sideDistX = 0;
	config->sideDistY = 0;
	config->deltaDistX = 0;
	config->deltaDistY = 0;
	config->stepX = 0;
	config->stepY = 0;
	config->side = 0;
	config->lineHeight = 0;
	config->drawStart = 0;
	config->drawEnd = 0;
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
	config->perpWallDist = 0;
	config->hit = 0;
	config->cameraX = 2 * config->x / (double)config->width - 1;
	config->rayDirX = config->dirX + config->planeX * config->cameraX;
	config->rayDirY = config->dirY + config->planeY * config->cameraX;
	config->mapX = (int)config->posX;
	config->mapY = (int)config->posY;
	config->movespeed = 0.05;
	config->rotspeed = 0.033 * 0.5;
	if (config->rayDirY == 0)
		config->deltaDistX = 0;
	else if (config->rayDirX == 0)
		config->deltaDistX = 1;
	else
		config->deltaDistX = sqrt(1 + (config->rayDirY
			* config->rayDirY) / (config->rayDirX *
			config->rayDirX));
	if (config->rayDirX == 0)
		config->deltaDistY = 0;
	else if (config->rayDirY == 0)
		config->deltaDistY = 1;
	else
		config->deltaDistY = sqrt(1 + (config->rayDirX *
			config->rayDirX) / (config->rayDirY *
			config->rayDirY));
}

void	set_player(t_list *config)
{
	config->posX = config->startX + 0.5;
	config->posY = config->startY + 0.5;
	if (config->player_orientation == 'N')
	{
		config->dirX = -1;
		config->planeY = 0.66;
	}
	else if (config->player_orientation == 'S')
	{
		config->dirX = 1;
		config->planeY = -0.66;
	}
	else if (config->player_orientation == 'E')
	{
		config->dirY = 1;
		config->planeX = 0.66;
	}
	else
	{
		config->dirY = -1;
		config->planeX = -0.66;
	}
}

void	step_and_sideDist(t_list *config)
{
	if (config->rayDirX < 0)
	{
		config->stepX = -1;
		config->sideDistX = (config->posX - config->mapX)
							* config->deltaDistX;
	}
	else
	{
		config->stepX = 1;
		config->sideDistX = (config->mapX + 1.0 - config->posX)
							* config->deltaDistX;
	}
	if (config->rayDirY < 0)
	{
		config->stepY = -1;
		config->sideDistY = (config->posY - config->mapY)
							* config->deltaDistY;
	}
	else
	{
		config->stepY = 1;
		config->sideDistY = (config->mapY + 1.0 - config->posY)
							* config->deltaDistY;
	}
}

void	check_hit(t_list *config, char **map)
{
	while (config->hit == 0)
	{
		if (config->sideDistX < config->sideDistY)
        {
			config->sideDistX += config->deltaDistX;
			config->mapX += config->stepX;
			config->side = 0;
        }
        else
        {
			config->sideDistY += config->deltaDistY;
			config->mapY += config->stepY;
			config->side = 1;
        }
		if (map[config->mapX][config->mapY] == '1') 
			config->hit = 1;
	}
}

void	distance_and_lines(t_list *config, char **map)
{
	if (config->side == 0)
		config->perpWallDist = (config->mapX - config->posX +
		(1 - config->stepX) / 2) / config->rayDirX;
	else
		config->perpWallDist = (config->mapY - config->posY +
		(1 - config->stepY) / 2) / config->rayDirY;
	config->lineHeight = (int)(config->height / config->perpWallDist);
	config->drawStart = -config->lineHeight / 2 + config->height / 2;
	if (config->drawStart < 0)
		config->drawStart = 0;
	config->drawEnd = config->lineHeight / 2 + config->height / 2;
	if (config->drawEnd >= config->height)
		config->drawEnd = config->height - 1;
}

void	choice_texture(t_list *config, char **map)
{
	if (config->side == 0 && config->rayDirX < 0)
		config->texNum = 0;
	if (config->side == 0 && config->rayDirX >= 0)
		config->texNum = 1;
	if (config->side == 1 && config->rayDirY < 0)
		config->texNum = 2;
	if (config->side == 1 && config->rayDirY >= 0)
		config->texNum = 3;
}

void	texture_calculation(t_list *config, char **map)
{
	if (config->side == 0)
		config->wallX = config->posY + config->perpWallDist * config->rayDirY;
	else
		config->wallX = config->posX + config->perpWallDist * config->rayDirX;
	config->wallX -= floor(config->wallX);
	config->texX = (int)(config->wallX * (double)config->texture[config->texNum].width);
	if (config->side == 0 && config->rayDirX > 0)
		config->texX = config->texture[config->texNum].width - config->texX - 1;
	if (config->side == 1 && config->rayDirY < 0)
		config->texX = config->texture[config->texNum].width - config->texX - 1;
}

void	init_draw(t_list *config, char **map)
{
	int	i;
	int	j;

	config->drawEnd = config->height - config->drawStart;

	i = config->drawEnd;
	j = -1;
	while (++j < config->drawStart)
		config->data.addr[j * config->data.line_length / 4 + config->x] = config->final_ceiling;
	if (j <= config->drawEnd)
		draw_text(config, map, config->x, j);
	j = i;
	while (++j < config->height)
		config->data.addr[j * config->data.line_length / 4 + config->x] = config->final_floor;
}

void	draw_text(t_list *config, char **map, int x, int y)
{
	y = config->drawStart - 1;
	choice_texture(config, map);
	config->step = 1.0 * config->texture[0].height / config->lineHeight;
	texture_calculation(config, map);
	config->texPos = (config->drawStart - config->height / 2 +
		config->lineHeight / 2) * config->step;
	while (++y <= config->drawEnd)
	{
		config->texY = (int)config->texPos & (config->texture[config->texNum].height - 1);
		config->texPos += config->step;
		if (y < config->height && x < config->width)
			config->data.addr[y * config->data.line_length / 4 + x] = 
			config->texture[config->texNum].addr[config->texY * config->texture[config->texNum].line_length / 4 + config->texX];
	}
}