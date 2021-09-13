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
		if (buf[0] == '\n')
			(*linenbr)++;
	}
}
