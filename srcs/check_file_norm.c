#include "../includes/cub3d.h"

void	check_floor_norm(char *str, int *i)
{
	while (str[(*i)] && str[(*i)] == ' ')
		(*i)++;
	(*i)++;
	while (str[(*i)] && str[(*i)] == ' ')
		(*i)++;
}

void	check_ceiling_norm(char *str, int *i)
{
	while (str[(*i)] && str[(*i)] == ' ')
		(*i)++;
	(*i)++;
	while (str[(*i)] && str[(*i)] == ' ')
		(*i)++;
}
