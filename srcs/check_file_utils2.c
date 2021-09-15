/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:12:49 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/15 19:12:50 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_errors(t_list *config, char **map)
{
	if (config->north != 1 || config->south != 1
		|| config->east != 1 || config->west != 1
		|| config->c != 1 || config->f != 1)
	{
		printf("Error\nConfigurations incorrectes\n");
		free_array(&map);
		exit(0);
	}
}
