/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:08:23 by ngenadie          #+#    #+#             */
/*   Updated: 2022/02/10 04:17:37 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_close_win(t_mlx_data *data, t_dynarray *darr)
{
	ft_free_all(darr);
	mlx_destroy_image(data->mlx, data->big_img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

void	ft_player_coord(t_mlx_data *data, t_dynarray *darr)
{
	uint64_t	i;
	uint64_t	j;
	char		**board;

	i = 0;
	j = 0;
	board = (char **)darr->list;
	while (i < darr->nb_cells)
	{
		while (board[i][j])
		{
			if (board[i][j] == 'P')
			{
				data->i = i;
				data->j = j;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_move(t_mlx_data *data, t_dynarray *darr, uint64_t i, uint64_t j)
{
	char	**board;

	board = (char **)darr->list;
	if (board[i][j] == 'C')
		ft_collect(data, darr, i, j);
	if (board[i][j] == '0')
		ft_walk(data, darr, i, j);
	if (board[i][j] == 'E')
		ft_exit(data, darr);
}

int	ft_key_hook(int key, t_mlx_data *data)
{
	ft_player_coord(data, data->darr);
	if (key == ESC)
		ft_close_win(data, data->darr);
	if (key == RIGHT)
		ft_move_right(data, data->darr);
	if (key == LEFT)
		ft_move_left(data, data->darr);
	if (key == UP)
		ft_move_up(data, data->darr);
	if (key == DOWN)
		ft_move_down(data, data->darr);
	ft_draw_board(*data, *data->darr);
	return (0);
}
