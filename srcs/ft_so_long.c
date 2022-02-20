/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:10:56 by ngenadie          #+#    #+#             */
/*   Updated: 2022/02/20 19:36:27 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_draw_square(t_mlx_data data, char *path_string, int i, int j)
{
	data.img_ptr = mlx_xpm_file_to_image(data.mlx, path_string,
			&data.width, &data.height);
	if (data.img_ptr == NULL)
		return (-1);
	mlx_put_image_to_window(data.mlx, data.win,
		data.img_ptr, i * 48, j * 48);
	if (data.img_ptr)
		mlx_destroy_image(data.mlx, data.img_ptr);
	return (0);
}

int	ft_draw_board(t_mlx_data data, t_dynarray darr)
{
	uint64_t	i;
	uint64_t	j;
	char		**board;

	i = 0;
	j = 0;
	board = ((char **)darr.list);
	while (i < darr.nb_cells && board[i][j])
	{
		while (board[i][j])
		{
			if (ft_draw(data, board, i, j) == -1)
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_verif_map(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] != 'P' && s[i] != '1' && s[i] != '0'
			&& s[i] != 'C' && s[i] != 'E')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_get_map(char **argv, t_dynarray *darr, t_mlx_data *data)
{
	int		fd;
	int		ret;
	char	*s;

	s = NULL;
	if (ft_verif_path(argv[2]) != 0)
		return (free_dynarray(darr), -1);
	fd = open(argv[2], O_RDONLY);
	if (fd == -1)
		return (free_dynarray(darr), -1);
	while (ft_get_map_ret(&ret, fd, &s) == 1)
	{
		if (ret == -1 || s == NULL)
			return (ft_free(s), ft_free_all(darr), -1);
		if (ft_verif_map(s))
			return (ft_free(s), ft_free_all(darr), -1);
		if (push_dynarray(darr, &s, 1, 0) == -1)
			return (ft_free(s), ft_free_all(darr), -1);
		ft_count_obj(s, data);
	}
	if (darr->nb_cells < 3)
		return (ft_free(s), ft_free_all(darr), -1);
	if (data->nb_player != 1 || data->nb_collectibles < 1 || data->nb_exit != 1)
		return (ft_free(s), ft_free_all(darr), -1);
	return (ft_free(s), ft_verif_closed_rect(darr));
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;
	t_dynarray	darr;

	if (argc != 3)
		return (ft_print_error(2), -1);
	ft_memset(&data, 0, sizeof(data));
	data.width = 48;
	data.height = 48;
	if (init_dynarray(&darr, 1, 8))
		return (ft_print_error(1), -1);
	data.darr = &darr;
	if (ft_get_map(argv, &darr, &data) == -1)
		return (ft_print_error(3), -1);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (ft_print_error(5), -1);
	if (display(&data, &darr, argv) == -1)
		return (-1);
	mlx_hook(data.win, 2, 1L << 0, ft_key_hook, &data);
	mlx_hook(data.win, 17, 1L << 17, &ft_close_win, &data);
	mlx_loop(data.mlx);
}
