/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:13:13 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/15 19:13:14 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_right(char **map, int *i, int *j, t_list *config)
{
	if (*i == 0 || *j == 0 || *i >= (config->line_nbr - 1)
		|| *j >= config->column_nbr)
		error_msg(*i, *j, &(*config));
	while (config->error == 0 && map[(*i)][(*j)] && map[(*i) + 1]
			&& map[(*i) + 1][(*j)] && map[(*i) + 1][(*j)] != '1'
			&& map[(*i)][(*j) + 1] && map[(*i)][(*j) + 1] == '1')
	{
		(*i)++;
		if (*i >= config->line_nbr || map[(*i) + 1][(*j)] == ' ')
			error_msg(*i, *j, &(*config));
		if (config->error == 0 && map[(*i)][(*j)]
			&& map[(*i)][(*j) + 1]
			&& map[(*i)][(*j) + 1] != '1')
		{
			(*j)++;
			check_top(map, i, j, &(*config));
		}
	}
}

void	check_top(char **map, int *i, int *j, t_list *config)
{
	if (*i == 0 || *j == 0 || *i >= config->line_nbr
		|| *j >= config->column_nbr)
		error_msg(*i, *j, &(*config));
	while (config->error == 0 && map[(*i)][(*j)]
			&& map[(*i)][(*j) + 1] && map[(*i)][(*j) + 1] != '1'
			&& map[(*i) - 1][(*j)] && map[(*i) - 1][(*j)] == '1')
	{
		(*j)++;
		if (*j >= config->column_nbr || map[(*i)][(*j) + 1] == ' ')
			error_msg(*i, *j, &(*config));
		if (config->error == 0 && map[(*i)][(*j)]
			&& map[(*i) - 1][(*j)]
			&& map[(*i) - 1][(*j)] != '1')
		{
			(*i)--;
			check_left(map, i, j, &(*config));
		}
	}
}

void	check_left(char **map, int *i, int *j, t_list *config)
{
	if (*i == 0 || *j == 0 || *i >= config->line_nbr
		|| *j >= config->column_nbr)
		error_msg(*i, *j, &(*config));
	while (config->error == 0 && map[(*i)][(*j)] && map[(*i) - 1][(*j)]
			&& map[(*i) - 1][(*j)] != '1' && map[(*i)][(*j) - 1]
			&& map[(*i)][(*j) - 1] == '1')
	{
		(*i)--;
		if (*i == 0 || map[(*i) - 1][(*j)] == ' ')
			error_msg(*i, *j, &(*config));
		if (config->error == 0 && map[(*i)][(*j)]
			&& map[(*i)][(*j) - 1]
			&& map[(*i)][(*j) - 1] != '1')
		{
			(*j)--;
			check_bottom(map, i, j, &(*config));
		}
	}
}

void	check_bottom(char **map, int *i, int *j, t_list *config)
{
	if (*i == 0 || *j == 0 || *i >= config->line_nbr
		|| *j >= config->column_nbr)
		error_msg(*i, *j, &(*config));
	while (config->error == 0 && map[(*i)][(*j)] && map[(*i)][(*j) - 1]
			&& map[(*i)][(*j) - 1] != '1' && map[(*i) + 1][(*j)]
			&& map[(*i) + 1][(*j)] == '1')
	{
		(*j)--;
		if (*j == 0 || map[(*i)][(*j) - 1] == ' ')
			error_msg(*i, *j, &(*config));
		if (config->error == 0 && map[(*i)][(*j)]
			&& map[(*i) + 1][(*j)] && map[(*i) + 1][(*j)] != '1')
		{
			(*i)++;
			check_right(map, i, j, &(*config));
		}
	}
}
