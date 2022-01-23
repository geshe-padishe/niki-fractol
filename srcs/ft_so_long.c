/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:10:56 by ngenadie          #+#    #+#             */
/*   Updated: 2022/01/23 01:32:59 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int ft_draw_board(mlx_data data, char **map)
{
	int i;
	int j;

	while (i < data.x)
	{
		while (j < data.y)
		{
			if (maps[i][j] == 'P')
			{
				data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./images/hero.xpm", &width, &height);
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, i * 48, j * 48);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	mlx_data data;
	int		endian;
	int		bits_per_pixel;
	int		size_line;
	int		width;
	int		height;

	(void)argc;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		printf("failed to initialize mlx");

	data.win_ptr = mlx_new_window(data.mlx_ptr, 48 * 3, 48, argv[1]);
	if (data.win_ptr == NULL)
		printf("failed to initialize window");

	data.img_ptr = mlx_new_image(data.mlx_ptr, 3000, 3000);
	if (data.img_ptr == NULL)
		printf("failed to create image");

	mlx_get_data_addr(data.img_ptr, &bits_per_pixel, &size_line, &endian);
	printf("bits_per_pixel: %d, size_line: %d, endian: %d\n",
			bits_per_pixel, size_line, endian);

	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./images/hero.xpm", &width, &height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./images/treasure.xpm", &width, &height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 48 * 1, 0);
	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./images/rock.xpm", &width, &height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 48 * 2, 0);
	mlx_loop(data.mlx_ptr);
}
