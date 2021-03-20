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

char    **ft_parse_file(char **argv, char **file, t_list *options)
{
    char    **line;
    int     fd;
    int     i;

    line = NULL;
    i = 0;
    ft_copy_file(argv, &line);
    malloc_string_struct(options, line);
    return (file);
}
