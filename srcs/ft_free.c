#include "../includes/cub3d.h"

void	free_str_and_map(t_list	*config, char **map)
{
	int	i;

	i = 0;
	if (config->north_t)
		free(config->north_t);
	if (config->south_t)
		free(config->south_t);
	if (config->west_t)
		free(config->west_t);
	if (config->east_t)
		free(config->east_t);
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map[i]);
		free(map);
	}
	clear_mlx(config);
}

int	clear_mlx(t_list *config)
{
	if (config->texerror == 0)
	{
		if (config->data.img)
			mlx_destroy_image(config->data.mlx_ptr, config->data.img);
		if (config->texture[0].img)
			mlx_destroy_image(config->data.mlx_ptr, config->texture[0].img);
		if (config->texture[1].img)
			mlx_destroy_image(config->data.mlx_ptr, config->texture[1].img);
		if (config->texture[2].img)
			mlx_destroy_image(config->data.mlx_ptr, config->texture[2].img);
		if (config->texture[3].img)
			mlx_destroy_image(config->data.mlx_ptr, config->texture[3].img);
		if (config->data.mlx_win)
			mlx_destroy_window(config->data.mlx_ptr, config->data.mlx_win);
	}
	exit(0);
}
