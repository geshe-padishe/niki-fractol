/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:15:21 by ngenadie          #+#    #+#             */
/*   Updated: 2022/02/20 01:29:24 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_collect(t_mlx_data *data, t_dynarray *darr, uint64_t i, uint64_t j)
{
	char	**board;

	board = (char **)darr->list;
	data->nb_collected++;
	board[i][j] = 'P';
	board[data->i][data->j] = '0';
	data->moves++;
	ft_putnbr(data->moves);
	write(1, "\n", 1);
	ft_player_coord(data, darr);
}

void	ft_walk(t_mlx_data *data, t_dynarray *darr, uint64_t i, uint64_t j)
{
	char	**board;

	board = (char **)darr->list;
	board[i][j] = 'P';
	board[data->i][data->j] = '0';
	data->moves++;
	ft_putnbr(data->moves);
	write(1, "\n", 1);
	ft_player_coord(data, darr);
}

void	ft_exit(t_mlx_data *data)
{
	if (data->nb_collectibles == data->nb_collected)
	{
		ft_putnbr(data->moves);
		write(1, "\n", 1);
		ft_close_win(data);
	}
}

int	ft_draw(t_mlx_data data, char **board, uint64_t i, uint64_t j)
{
	if (board[i][j] == 'P')
		if (ft_draw_square(data, "./images/hero.xpm", j, i) == -1)
			return (-1);
	if (board[i][j] == '1')
		if (ft_draw_square(data, "./images/rock.xpm", j, i) == -1)
			return (-1);
	if (board[i][j] == '0')
		if (ft_draw_square(data, "./images/background.xpm", j, i) == -1)
			return (-1);
	if (board[i][j] == 'E')
		if (ft_draw_square(data, "./images/exit.xpm", j, i) == -1)
			return (-1);
	if (board[i][j] == 'C')
		if (ft_draw_square(data, "./images/treasure.xpm", j, i) == -1)
			return (-1);
	return (0);
}

void	ft_putnbr(int pid)
{
	char	c;

	c = pid % 10 + 48;
	if (pid > 0)
		ft_putnbr(pid / 10);
	if (pid > 0)
		write(1, &c, 1);
}
