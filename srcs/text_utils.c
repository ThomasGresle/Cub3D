#include "../includes/cub3d.h"

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
