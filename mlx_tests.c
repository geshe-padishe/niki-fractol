/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:10:56 by ngenadie          #+#    #+#             */
/*   Updated: 2022/01/07 20:17:06 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		endian;
	int		bits_per_pixel;
	int		size_line;

	(void)argc;
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		printf("failed to initialize mlx");

	win_ptr = mlx_new_window(mlx_ptr, 500, 500, argv[1]);
	if (win_ptr == NULL)
		printf("failed to initialize window");

	img_ptr = mlx_new_image(mlx_ptr, 3000, 3000);
	if (img_ptr == NULL)
		printf("failed to create image");

	mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	printf("bits_per_pixel: %d, size_line: %d, endian: %d\n", bits_per_pixel, size_line, endian);
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, mlx_get_color_value(mlx_ptr, 1638400));
	mlx_loop(mlx_ptr);
}
