/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgresle <tgresle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:46:43 by tgresle           #+#    #+#             */
/*   Updated: 2020/03/10 20:23:04 by tgresle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	stop_read(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	cpy_until_sep(char **str, char **line, char **buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	free(*buf);
	while ((*str) && (*str)[i] && (*str)[i] != '\n')
		i++;
	*line = malloc(sizeof(char) * (i + BUFFER_SIZE));
	if (!(*line))
		return (-1);
	while ((*str)[j] && j < i)
	{
		(*line)[j] = (*str)[j];
		j++;
	}
	(*line)[j] = 0;
	tmp = *str;
	(*str) = ft_substr((*str), i + 1, ft_strlen((*str)));
	free(tmp);
	return (1);
}

static int	ft_control(char **str, int fd, char **line, char **buf)
{
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(*str))
		*str = ft_strdup("");
	if (stop_read(*str))
	{
		*buf = ft_strdup("");
		cpy_until_sep(str, line, buf);
		return (1);
	}
	*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(*buf))
		return (-1);
	return (0);
}

int	norm_util(char **str, int fd)
{
	free(str[fd]);
	str[fd] = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int				ret;
	int				check;
	char			*buf;
	static char		*str[1024];
	char			*tmp;

	ret = 1;
	check = ft_control(&str[fd], fd, line, &buf);
	if (check != 0)
		return (check);
	while (stop_read(str[fd]) == 0 && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = 0;
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], buf);
		free(tmp);
	}
	if (cpy_until_sep(&str[fd], line, &buf) == 1 && ret == 0 && !(*str[fd]))
		return (norm_util(str, fd));
	return (1);
}
