/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:11:52 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/17 18:56:37 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_strcmp(char *s1, char *s2, int j)
{
	int	i;

	i = 0;
	while (s1[j] && s2[i] && s1[j] == s2[i])
	{
		i++;
		j++;
	}
	if (s1[j] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}

int	ft_strlen_parsing(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] >= 33 && str[i] <= 126)
	{
		i++;
		j++;
		if (str[i] && str[i + 1] && str[i] == ' ')
		{
			j++;
			while (str[i] && str[i] == ' ')
			{
				i++;
			}
		}
	}
	if (str[i] && str[i - 1] && str[i] == '\0' && str[i - 1] == ' ')
		j--;
	j++;
	return (j);
}

void	ft_strcpy_parsing(char *dst, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] && str[j] == ' ')
		j++;
	while (str[j] && str[j] != ' ')
		j++;
	while (str[j] && str[j] == ' ')
		j++;
	while (str[j] && str[j] >= 33 && str[j] <= 126)
	{
		dst[i++] = str[j++];
		while (str[j] && str[j] == ' ')
		{
			j++;
			if (str[j] && str[j] != ' ')
			{
				dst[i] = ' ';
				i++;
			}
		}
	}
	dst[i] = '\0';
}

void	ft_strcpy_numbers(char *dst, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] && str[j] == ' ')
		j++;
	while (str[j] && str[j] != ' ')
		j++;
	while (str[j] && str[j] == ' ')
		j++;
	while (str[j] && ((str[j] >= '0' && str[j] <= '9') || str[j] == '-'))
	{
		dst[i] = str[j];
		i++;
		j++;
		if (str[j] && (str[j] == ' ' || str[j] == ','))
		{
			dst[i] = ' ';
			while (str[j] && (str[j] == ' ' || str[j] == ','))
				j++;
			i++;
		}
	}
	dst[i] = '\0';
}

void	parse_map_norm(char **map, int *i, int j)
{
	while (map[(*i)] && j < (int)(ft_strlen(map[(*i)])) && map[(*i)][j]
		&& !(map[(*i)][j] >= 48 && map[(*i)][j] <= 57))
	{
		j = 0;
		while (map[(*i)][j] == ' ')
			j++;
		if (j < (int)(ft_strlen(map[(*i)])) &&
			!(map[(*i)][j] >= 48 && map[(*i)][j] <= 57))
		{
			(*i)++;
			j = 0;
		}
		while (map[(*i)] && map[(*i)][0] == 0)
			(*i)++;
	}
}
