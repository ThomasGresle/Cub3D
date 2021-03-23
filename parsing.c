#include "cub3d.h"

void    ft_copy_file(char **argv, char ***line)
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
    if(!(*line = malloc(sizeof(char *) * (linenbr))))
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

void	ft_parse_file(char **argv, char ***map, t_list *options)
{
    char    **line;
    int     fd;
    int     i;

    line = NULL;
    i = 0;
    ft_copy_file(argv, &line);
    malloc_string_struct(options, line);
	ft_parse_map(&(*map), line);
	free_array(&line);
    return ;
}

void	ft_parse_map(char ***map, char **line)
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
		while (line[i + j][k])
			k++;
		if (k > l)
			l = k;
		j++;
	}
	ft_malloc_map(&(*map), j, l);
	create_map(&(*map), line, i);
}
