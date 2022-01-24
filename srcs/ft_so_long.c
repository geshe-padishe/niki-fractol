/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:10:56 by ngenadie          #+#    #+#             */
/*   Updated: 2022/01/24 20:35:04 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int ft_draw_square(t_mlx_data data, char *path_string, int i, int j)
{
	printf("data_width = %i\ndata_height = %i\n",
			data.width, data.height);
	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, path_string,
										&data.width, &data.height);
	if (data.img_ptr == NULL)
		return (-1);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr,
							data.img_ptr, i * 48, j * 48);
	return (0);
}

int ft_draw_board(t_mlx_data data, t_dynarray darr)
{
	uint64_t	i;
	uint64_t	j;
	char		**board;

	i = 0;
	j = 0;
	board = ((char**)darr.list);
	while (i < darr.nb_cells && board[i][j])
	{
		while (board[i][j])
		{
			printf("board[i][j] = %c\n", board[i][j]);
			if (board[i][j] == 'P')
				if (ft_draw_square(data, "./images/hero", i, j) == -1)
					return (-1);
			if (board[i][j] == '1')
				if (ft_draw_square(data, "./images/rock", i, j) == -1)
					return (-1);
			if (board[i][j] == '0')
				if (ft_draw_square(data, "./images/background", i, j) == -1)
					return (-1);
			if (board[i][j] == 'E')
				if (ft_draw_square(data, "./images/exit", i, j) == -1)
					return (-1);
			if (board[i][j] == 'C')
				if (ft_draw_square(data, "./images/treasure", i, j) == -1)
					return (-1);
		}
	}
	return (0);
}

void ft_print_darr(t_dynarray darr)
{
	uint64_t i;

	i = 0;
	dprintf(1, "nb_cells = %lu\n", darr.nb_cells);
	while (i < darr.nb_cells)
	{
		printf("line[%lu] = %s\n", i, ((char**)darr.list)[i]);
		i++;
	}
}

int ft_get_map(char **argv, t_dynarray *darr)
{
	int		fd;
	int		ret;
	char	*s;

	s = NULL;
	if ((fd = open(argv[2], O_RDONLY)) == -1)
		return (-1);
	while ((ret = get_next_line(fd, &s)) == 1)
	{
		if (ret == -1)
		{
			printf("ret: -1");
			return (-1);
		}
		if (push_dynarray(darr, &s, 1, 1) == -1)
			return (-1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx_data	data;
	t_dynarray	darr;

	(void)argc;
	init_dynarray(&darr, 0, 8);
	data.width = 48;
	data.height = 48;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		printf("failed to initialize mlx");

	data.win_ptr = mlx_new_window(data.mlx_ptr, 48 * 20, 48 * 20, argv[1]);
	if (data.win_ptr == NULL)
		printf("failed to initialize window");

	data.img_ptr = mlx_new_image(data.mlx_ptr, 3000, 3000);
	if (data.img_ptr == NULL)
		printf("failed to create image");

	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./images/rock",
						&data.width, &data.height);
	printf("data.img_ptr = %p\n", data.img_ptr);
	if (ft_get_map(argv, &darr) == -1)
	{
		printf("get_map: -1");
		return (-1);
	}
	ft_print_darr(darr);
	if (ft_draw_board(data, darr) == -1)
	{
		printf("draw_board: -1");
		return (-1);
	}
	mlx_loop(data.mlx_ptr);
}
