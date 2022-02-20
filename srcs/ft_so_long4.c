/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 03:06:18 by ngenadie          #+#    #+#             */
/*   Updated: 2022/02/10 04:34:50 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_print_error(int erreur)
{
	if (erreur == 0)
		write(1, "Error\nSomething went wrong\n", 28);
	if (erreur == 1)
		write(1, "Error\nDynarray Error", 20);
	if (erreur == 2)
		write(1, "Error\nWrong args", 16);
	if (erreur == 3)
		write(1, "Error\nMap Error", 15);
	if (erreur == 4)
		write(1, "Error\nFile Error", 16);
	if (erreur == 5)
		write(1, "Error\nMlx Error", 15);
}

int	display(t_mlx_data *data, t_dynarray *darr, char **argv)
{
	data->win = mlx_new_window(data->mlx,
			48 * ft_strlen(((char **)darr->list)[0]),
			48 * darr->nb_cells, argv[1]);
	if (data->win == NULL)
		return (free(data->mlx), free_dynarray(darr), ft_print_error(5), -1);
	data->img_ptr = mlx_new_image(data->mlx,
			48 * ft_strlen(((char **)darr->list)[0]), 48 * darr->nb_cells);
	if (data->img_ptr == NULL)
		return (mlx_destroy_window(data->mlx, data->win),
			mlx_destroy_display(data->mlx),
			free_dynarray(darr), free(data->mlx), ft_print_error(5), -1);
	data->big_img_ptr = data->img_ptr;
	if (ft_draw_board(*data, *darr) == -1)
		return (ft_print_error(4), ft_close_win(data), -1);
	return (0);
}
