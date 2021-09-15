/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:13:23 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/15 19:13:23 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_list	config;
	int		i;

	config.map = NULL;
	i = 0;
	struct_init(&config);
	if (check_and_parse(argc, argv, &config.map, &config) == 0)
	{
		free_str_and_map(&config, config.map);
		return (0);
	}
	init_mlx(&config, config.map);
	free_str_and_map(&config, config.map);
	return (0);
}
