/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:13:52 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/15 19:13:53 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	malloc_string_struct(t_list *options, char **line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] && line[i][j] && line[i][j] == ' ')
			j++;
		if (line[i] && line[i][j] && line[i][j] == 'C')
			malloc_c(options, line[i]);
		if (line[i] && line[i][j] && line[i][j] == 'F')
			malloc_f(options, line[i]);
		if (line[i] && line[i][j] && line[i][j] == 'N')
			malloc_n(options, line[i]);
		if (line[i] && line[i][j] && line[i][j + 1]
			&& line[i][j] == 'S' && line[i][j + 1] == 'O')
			malloc_s(options, line[i]);
		if (line[i] && line[i][j] && line[i][j] == 'E')
			malloc_e(options, line[i]);
		if (line[i] && line[i][j] && line[i][j] == 'W')
			malloc_w(options, line[i]);
		i++;
		j = 0;
	}
}

void	free_array(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i])
		i++;
	while (i > 0)
	{
		free((*array)[i]);
		i--;
	}
	free((*array)[i]);
	free(*array);
}
