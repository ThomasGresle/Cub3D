/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:09:19 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/17 17:38:48 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	atoi_color(char *str, int *i)
{
	int	color;

	color = 0;
	while (str[(*i)] && str[(*i)] != ' ')
	{
		color = (color * 10) + (str[(*i)] - 48);
		(*i)++;
	}
	return (color);
}

void	error_color(int *i, char *str, t_list *config)
{
	if (str[(*i)] == '\0')
	{
		printf("Error\nSol ou plafond incorrect\n");
		free(str);
		free_str_and_map(config);
	}
}

int	final_color(t_list *config, char *str)
{
	int	color;
	int	i;

	color = 0;
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	error_color(&i, str, config);
	color = atoi_color(str, &i) * 65536;
	i++;
	error_color(&i, str, config);
	color += atoi_color(str, &i) * 256;
	i++;
	error_color(&i, str, config);
	color += atoi_color(str, &i);
	free(str);
	str = NULL;
	return (color);
}
