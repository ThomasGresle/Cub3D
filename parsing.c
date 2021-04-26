#include "cub3d.h"

void    ft_copy_file(char **argv, char ***line, int *error)
{
    int     i;
    int     ret;
    int     fd;
    int     linenbr;
    char    *buf;

    i = 0;
    ret = 0;
    linenbr = 0;
    if (!(buf = malloc(sizeof(char))))
        return ;
    fd = open(argv[1], O_RDONLY);
    while (ret = read(fd, buf, sizeof(char)))
    {
        if (ret == -1)
            return ;
        if (buf[0] == '\n')
            linenbr++;
    }
    close(fd);
    free(buf);
    linenbr++;
    if(!(*line = malloc(sizeof(char *) * (linenbr + 1))))
        return ;
    (*line)[linenbr] = '\0';
    fd = open(argv[1], O_RDONLY);
    while (linenbr > 0)
    {
        get_next_line(fd, &(*line)[i]);
        linenbr--;
        i++;
    }
    close(fd);
    return ;
}

int		ft_parse_file(char **argv, char ***map, t_list *options)
{
    char    **line;
	int		error;
    int     fd;
    int     i;

    line = NULL;
	error = 0;
    i = 0;
    ft_copy_file(argv, &line, &error);
	if (error == 0)
	{
		malloc_string_struct(options, line);
		ft_parse_map(&(*map), line, &(*options));
		free_array(&line);
		return (0);
	}
    return (1);
}

void	finish_map(char ***map, int l)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while ((*map)[i])
	{
		j = 0;
		k = l - 1;
		while ((*map)[i][j] && (*map)[i][j] == '0')
		{
			(*map)[i][j] = ' ';
			j++;
		}
		while ((*map)[i][k] && (*map)[i][k] == '0')
		{
			(*map)[i][k] = ' ';
			k--;
		}
		i++;
	}
}

void	ft_parse_map(char ***map, char **line, t_list *config)
{
	int i;
	int	j;
	int k;
	int l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (line[i] && line[i][0] != ' ' && !(line[i][0] >= 48 && line[i][0] <= 57))
		i++;
	while (line[i + j])
	{
		k = 0;
		while (line[i + j][k])
			k++;
		if (k > l)
			l = k;
		j++;
	}
	ft_malloc_map(&(*map), j, l, &(*config));
	create_map(&(*map), line, i, l);
	finish_map(&(*map), l);
}
