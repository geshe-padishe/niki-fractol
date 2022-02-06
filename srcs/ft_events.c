#include "ft_so_long.h"

void	ft_collect(t_mlx_data *data, t_dynarray *darr, uint64_t i, uint64_t j)
{
	char **board;

	board = (char **)darr->list;
	data->nb_collected++;
	board[i][j] = 'P';
	board[data->i][data->j] = '0';
	data->moves++;
	ft_player_coord(data, darr);
}

void	ft_walk(t_mlx_data *data, t_dynarray *darr, uint64_t i, uint64_t j)
{
	char **board;

	board = (char **)darr->list;
	board[i][j] = 'P';
	board[data->i][data->j] = '0';
	data->moves++;
	ft_player_coord(data, darr);
}

void	ft_exit(t_mlx_data *data, t_dynarray *darr)
{
	if (data->nb_collectibles == data->nb_collected)
	{
		//ft_putnbr(data->moves + 1);
		ft_close_win(data, darr);
	}
}
