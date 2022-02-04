/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:41:29 by ngenadie          #+#    #+#             */
/*   Updated: 2022/02/02 22:41:10 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_get_map_ret(int *ret, int fd, char **s)
{
	*ret = get_next_line(fd, s);
	return (*ret);
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] - str2[i] != 0)
			return (str[i] - str2[i]);
		i++;
	}
	return (str[i] - str2[i]);
}

int	ft_verif_path(char *path)
{
	int	i;

	i = 0;
	if (path[i] == '.')
		return (-1);
	while (path[i] && path[i] != '.' && path[i + 1])
		i++;
	if (path[i] != '.')
		return (-1);
	return (ft_strcmp(&path[i], ".ber"));
}

void	ft_print_darr(t_dynarray darr)
{
	uint64_t i;

	i = 0;
	dprintf(1, "nb_cells = %lu\n", darr.nb_cells);
	while (i < darr.nb_cells)
	{
		dprintf(1, "line[%lu] = %s\n", i, ((char**)darr.list)[i]);
		i++;
	}
}

void	ft_free_all(t_dynarray *darr)
{
	uint64_t	i;

	i = 0;
	while (i < darr->nb_cells)
	{
		if (((char **)darr->list)[i])
		{
			free(((char **)darr->list)[i]);
			((char **)darr->list)[i] = NULL;
		}
		i++;
	}
	free_dynarray(darr);
}
