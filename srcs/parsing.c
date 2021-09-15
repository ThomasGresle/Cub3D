#include "../includes/cub3d.h"

void	norm_utils_copy(int *linenbr, int fd, char ***line, int *i)
{
	while (*linenbr > 0)
	{
		get_next_line(fd, &(*line)[(*i)]);
		(*linenbr)--;
		(*i)++;
	}
	close(fd);
}

void	ft_copy_file(char **argv, char ***line)
{
	int		i;
	int		ret;
	int		fd;
	int		linenbr;
	char	*buf;

	i = 0;
	ret = 1;
	linenbr = 0;
	fd = 0;
	buf = malloc(sizeof(char));
	if (!(buf))
		return ;
	fd = open(argv[1], O_RDONLY);
	util_norm_copy2(&ret, &fd, buf, &linenbr);
	util_norm_copy(fd, buf, &linenbr);
	*line = malloc(sizeof(char *) * (linenbr + 1));
	if (!(*line))
		return ;
	(*line)[linenbr] = 0;
	fd = open(argv[1], O_RDONLY);
	norm_utils_copy(&linenbr, fd, &(*line), &i);
	return ;
}

int	ft_parse_file(char **argv, char ***map, t_list *options)
{
	char	**line;
	int		error;
	int		i;

	line = NULL;
	error = 0;
	i = 0;
	ft_copy_file(argv, &line);
	ft_check_options(line, options);
	if (error == 0)
	{
		malloc_string_struct(options, line);
		ft_parse_map(&(*map), &(*line), options);
		free_array(&line);
		return (0);
	}
	return (1);
}

void	finish_map(char ***map, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while ((*map)[i])
	{
		j = 0;
		k = l - 1;
		while ((*map)[i] && (*map)[i][j] && (*map)[i][j] == '0')
		{
			(*map)[i][j] = ' ';
			j++;
		}
		while ((*map)[i] && (*map)[i][k] && (*map)[i][k] == '0')
		{
			(*map)[i][k] = ' ';
			k--;
		}
		i++;
	}
}

void	ft_parse_map(char ***map, char **line, t_list *config)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (line[i] && line[i][0] == 0)
		i++;
	parse_map_norm(line, &i, j);
	j = 0;
	while (line[i + j])
	{
		k = 0;
		while (line[i + j] && line[i + j][k])
			k++;
		if (k > l)
			l = k;
		j++;
	}
	ft_malloc_map(&(*map), j, l, config);
	create_map(&(*map), &(*line), i, l);
	finish_map(&(*map), l);
}
