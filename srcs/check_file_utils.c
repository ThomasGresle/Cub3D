/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:12:44 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/15 19:12:45 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_text_n(char *str, t_list *config, int *error)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i + 1] && str[i + 1] == 'O')
		i += 2;
	else
		*error = 1;
	while (str[i] && str[i] == ' ' && *error == 0)
		i++;
	if (str[i] && str[i + 1] && (str[i] != '.' || str[i + 1] != '/'))
		*error = 1;
	i += 2;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		*error = 1;
	config->north++;
}

void	check_text_s(char *str, t_list *config, int *error)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i + 1] && str[i + 1] == 'O')
		i += 2;
	else
		*error = 1;
	while (str[i] && str[i] == ' ' && *error == 0)
		i++;
	if (str[i] && str[i + 1] && (str[i] != '.' || str[i + 1] != '/'))
		*error = 1;
	i += 2;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		*error = 1;
	config->south++;
}

void	check_text_e(char *str, t_list *config, int *error)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i + 1] && str[i + 1] == 'A')
		i += 2;
	else
		*error = 1;
	while (str[i] && str[i] == ' ' && *error == 0)
		i++;
	if (str[i] && str[i + 1] && (str[i] != '.' || str[i + 1] != '/'))
		*error = 1;
	i += 2;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		*error = 1;
	config->east++;
}

void	check_text_w(char *str, t_list *config, int *error)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i + 1] && str[i + 1] == 'E')
		i += 2;
	else
		*error = 1;
	while (str[i] && str[i] == ' ' && *error == 0)
		i++;
	if (str[i] && str[i + 1] && (str[i] != '.' || str[i + 1] != '/'))
		*error = 1;
	i += 2;
	while (str[i] && str[i] != ' ')
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i])
		*error = 1;
	config->west++;
}

void	ft_check_text(char *str, t_list *config, int *error)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && str[i] == 'N')
		check_text_n(str, config, error);
	if (str[i] && str[i] == 'S')
		check_text_s(str, config, error);
	if (str[i] && str[i] == 'E')
		check_text_e(str, config, error);
	if (str[i] && str[i] == 'W')
		check_text_w(str, config, error);
}
