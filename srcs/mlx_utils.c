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
	free_str_and_map(config, map);
}
