/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_utils_norm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:13:18 by tgresle           #+#    #+#             */
/*   Updated: 2021/09/17 18:07:28 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	util_norm_copy(int fd, char *buf, int *linenbr)
{
	close(fd);
	free(buf);
	(*linenbr)++;
}

void	util_norm_copy2(int *ret, int *fd, char *buf, int *linenbr)
{
	while (*ret)
	{
		*ret = read(*fd, buf, sizeof(char));
		if (*ret == -1)
			return ;
		if (buf && buf[0] == '\n')
			(*linenbr)++;
	}
}
