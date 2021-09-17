/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:13:23 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/17 17:39:07 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_list	config;
	int		i;

	ft_bzero(&config, sizeof(t_list));
	if (BUFFER_SIZE < 1)
	{
		printf("Error\nBUFFER SIZE trop faible petit malin\n");
		return (0);
	}
	config.map = NULL;
	i = 0;
	struct_init(&config);
	if (check_and_parse(argc, argv, &config.map, &config) == 0)
	{
		free_str_and_map(&config);
		return (0);
	}
	init_mlx(&config, config.map);
	free_str_and_map(&config);
	return (0);
}
