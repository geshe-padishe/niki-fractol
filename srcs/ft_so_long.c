/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:10:56 by ngenadie          #+#    #+#             */
/*   Updated: 2022/01/24 00:32:25 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int ft_draw_square(t_mlx_data data, char *path_string, int i, int j)
{
	printf("DRAWING2");
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

	printf("DRAWING");
	i = 0;
	j = 0;
	board = ((char**)darr.list);
	while (i < darr.nb_cells && board[i][j])
	{
		while (board[i][j])
		{
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

int ft_get_map(char **argv, t_dynarray darr)
{
	int		fd;
	int		ret;
	char	*s;
	char		**board;

	board = ((char**)darr.list);
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
		if (push_dynarray(&darr, &s, 1, 1) == -1)
			return (-1);
	}
	dprintf(1, "BEFORE DPRINTF\n");
	dprintf(1, "board[0][0] = %c\n", board[0][0]);
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx_data	data;
	t_dynarray	darr;
	int			endian;
	int			bits_per_pixel;
	int			size_line;

	(void)argc;
	init_dynarray(&darr, 0, 8);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		printf("failed to initialize mlx");

	data.win_ptr = mlx_new_window(data.mlx_ptr, 48 * 20, 48 * 20, argv[1]);
	if (data.win_ptr == NULL)
		printf("failed to initialize window");

	data.img_ptr = mlx_new_image(data.mlx_ptr, 3000, 3000);
	if (data.img_ptr == NULL)
		printf("failed to create image");

	mlx_get_data_addr(data.img_ptr, &bits_per_pixel, &size_line, &endian);
	printf("bits_per_pixel: %d, size_line: %d, endian: %d\n",
			bits_per_pixel, size_line, endian);

	if (ft_get_map(argv, darr) == -1)
	{
		printf("get_map: -1");
		return (-1);
	}
	if (ft_draw_board(data, darr) == -1)
	{
		printf("draw_board: -1");
		return (-1);
	}
	mlx_loop(data.mlx_ptr);
}
