/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_norm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:12:38 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/16 21:55:36 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_floor_norm(char *str, int *i)
{
	while (str[(*i)] && str[(*i)] == ' ')
		(*i)++;
	(*i)++;
	while (str[(*i)] && str[(*i)] == ' ')
		(*i)++;
}

void	check_floor_norm2(char *str, int i, t_list *config, int *error)
{
	config->f++;
	if (str[i] && str[i] != 0)
		*error = 1;
}

void	check_ceiling_norm(char *str, int *i)
{
	while (str[(*i)] && str[(*i)] == ' ')
		(*i)++;
	(*i)++;
	while (str[(*i)] && str[(*i)] == ' ')
		(*i)++;
}

void	check_ceiling_norm2(char *str, int i, t_list *config, int *error)
{
	config->c++;
	if (str[i] && str[i] != 0)
		*error = 1;
}
