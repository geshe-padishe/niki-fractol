/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:41:29 by ngenadie          #+#    #+#             */
/*   Updated: 2022/01/27 05:29:00 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_get_map_ret(int *ret, int fd, char **s)
{
	*ret = get_next_line(fd, s);
	return (*ret);
}

int	ft_verif_path(char *path)
{
	int	i;

	i = 0;
	while (path[i] && path[i] != '.')
		i++;
	return (strcmp(&path[i], ".bar"));
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] && str2[i])
		i++;
	if (str[i] - str2[i] != 0)
		return (0);
	return (1);
}
