/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:14:38 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/15 19:14:38 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	malloc_n(t_list *options, char *line)
{
	int	i;

	i = 0;
	options->north_t = (char *)malloc(sizeof(char)
			* ft_strlen_parsing(line));
	if (!(options->north_t))
		return ;
	ft_strcpy_parsing(options->north_t, line);
}

void	malloc_s(t_list *options, char *line)
{
	int	i;

	i = 0;
	options->south_t = (char *)malloc(sizeof(char)
			* ft_strlen_parsing(line));
	if (!(options->south_t))
		return ;
	ft_strcpy_parsing(options->south_t, line);
}

void	malloc_e(t_list *options, char *line)
{
	int	i;

	i = 0;
	options->east_t = (char *)malloc(sizeof(char)
			* ft_strlen_parsing(line));
	if (!(options->east_t))
		return ;
	ft_strcpy_parsing(options->east_t, line);
}

void	malloc_w(t_list *options, char *line)
{
	int	i;

	i = 0;
	options->west_t = (char *)malloc(sizeof(char)
			* ft_strlen_parsing(line));
	if (!(options->west_t))
		return ;
	ft_strcpy_parsing(options->west_t, line);
}
