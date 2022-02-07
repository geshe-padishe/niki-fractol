/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:04:54 by ngenadie          #+#    #+#             */
/*   Updated: 2022/02/07 21:45:28 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	get_next_line2(char **str, char ***line, int nl_index, int len)
{
	if (len < 0)
		return (-1);
	nl_index = ft_nl_index(*str);
	if (nl_index == 0 || nl_index == ft_strlen(*str))
	{
		*str = ft_send_clean(*line, *str, ft_strlen(*str));
		if (!(*str))
			return (-1);
		free(*str);
		*str = NULL;
	}
	else
	{
		*str = ft_send_clean(*line, *str, nl_index);
		if (!(str))
			return (-1);
	}
	if (len == 0 && *str == NULL)
		return (0);
	return (1);
}

int	ft_one_line_malloc(char **str, int len)
{
	*str = (char *)malloc(len);
	if (!(*str))
		return (-1);
	return (0);
}

int	ft_nl(int *nl_index, char *str)
{
	*nl_index = ft_nl_index(str);
	return (*nl_index);
}

int	ft_len(int *len, int fd, char *buff)
{
	*len = read(fd, buff, BUFFER_SIZE);
	return (*len);
}
