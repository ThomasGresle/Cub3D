#include "../includes/cub3d.h"

void	util_norm_copy(int fd, char *buf, int *linenbr)
{
	close(fd);
	free(buf);
	linenbr++;
}
