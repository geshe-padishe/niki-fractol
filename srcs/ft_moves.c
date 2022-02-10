/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:05:29 by ngenadie          #+#    #+#             */
/*   Updated: 2022/02/08 21:05:30 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_move_right(t_mlx_data *data, t_dynarray *darr)
{
	ft_move(data, darr, data->i, data->j + 1);
}

void	ft_move_left(t_mlx_data *data, t_dynarray *darr)
{
	ft_move(data, darr, data->i, data->j - 1);
}

void	ft_move_up(t_mlx_data *data, t_dynarray *darr)
{
	ft_move(data, darr, data->i - 1, data->j);
}

void	ft_move_down(t_mlx_data *data, t_dynarray *darr)
{
	ft_move(data, darr, data->i + 1, data->j);
}
