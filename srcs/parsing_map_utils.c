/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:14:08 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/17 17:40:29 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_malloc_map(char ***map, int i, int j, t_list *config)
{
	int	k;

	k = 0;
	config->line_nbr = i;
	config->column_nbr = j;
	*map = malloc(sizeof(char *) * (i + 1));
	if (!(*map))
		free_str_and_map(config);
	while (k < i)
	{
		(*map)[k] = (char *)malloc(sizeof(char) * (j + 1));
		if (!((*map)[k]))
			free_str_and_map(config);
		k++;
	}
}

void	copy_line_in_map(char **map, char *str, int l)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			(*map)[i] = '0';
		else
			(*map)[i] = str[i];
		i++;
	}
	while (i < l)
	{
		(*map)[i] = '0';
		i++;
	}
	(*map)[i] = '\0';
}

void	create_map(char ***map, char **line, int i, int l)
{
	int	j;

	j = 0;
	while (line[i])
	{
		copy_line_in_map(&((*map)[j]), line[i], l);
		i++;
		j++;
	}
	(*map)[j] = 0;
}
