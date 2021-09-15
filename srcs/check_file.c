/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:12:55 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/15 19:12:56 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_floor(char *str, t_list *config, int *error)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	check_floor_norm(str, &i);
	while (str[i] && str[i] >= 48 && str[i] <= 57 && *error == 0)
	{
		j = 0;
		while (str[i] && str[i] >= 48 && str[i] <= 57 && j++ < 3)
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] >= 48 && str[i] <= 57)
			*error = 1;
		if (str[i] && str[i] == ',' && k++ < 2)
			i++;
		while (str[i] && str[i] == ' ')
			i++;
	}
	config->f++;
	if (str[i] && str[i] != 0)
		*error = 1;
}

void	ft_check_ceiling(char *str, t_list *config, int *error)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	check_ceiling_norm(str, &i);
	while (str[i] && str[i] >= 48 && str[i] <= 57 && *error == 0)
	{
		j = 0;
		while (str[i] && str[i] >= 48 && str[i] <= 57 && j++ < 3)
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] >= 48 && str[i] <= 57)
			*error = 1;
		if (str[i] && str[i] == ',' && k++ < 2)
			i++;
		while (str[i] && str[i] == ' ')
			i++;
	}
	config->c++;
	if (str[i] && str[i] != 0)
		*error = 1;
}

void	ft_check_floor_ceiling(char *str, t_list *config, int *error)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] == 'F')
		ft_check_floor(str, config, error);
	else
		ft_check_ceiling(str, config, error);
}

void	ft_check_options2(char **map, t_list *config, int i, int error)
{
	int	j;

	j = 0;
	if (error == 0 && config->count == 6)
	{
		while (map[i] && map[i][0] == 0)
			i++;
		while (map[i] && map[i][j] && map[i][j] == ' ')
			j++;
		if (map[i] && map[i][j] == 0)
			error = 1;
		while (map[i] && map[i][0] && (map[i][0] == '1'
			|| map[i][0] == '0' || map[i][0] == ' '))
			i++;
		while (map[i] && map[i][0] == 0)
			i++;
	}
	if (map[i] || error == 1 || config->count < 6)
	{
		printf("Error\nConfigurations incorrectes\n");
		free_array(&map);
		exit(0);
	}
	check_errors(config, map);
}

void	ft_check_options(char **map, t_list *config)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	error = 0;
	while (map[i] && config->count < 6 && error == 0)
	{
		j = 0;
		while (map[i] && map[i][0] == 0)
			i++;
		while (map[i] && map[i][j] && map[i][j] == ' ')
			j++;
		if (map[i] && map[i][j] && (map[i][j] == 'C' || map[i][j] == 'F'))
			ft_check_floor_ceiling(map[i], config, &error);
		else if (map[i] && map[i][j] && (map[i][j] == 'S'
			|| map[i][j] == 'E' || map[i][j] == 'W'
			|| map[i][j] == 'N'))
			ft_check_text(map[i], config, &error);
		else
			error = 1;
		config->count++;
		i++;
	}
	ft_check_options2(map, config, i, error);
}
