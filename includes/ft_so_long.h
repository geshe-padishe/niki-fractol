/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:09:48 by ngenadie          #+#    #+#             */
/*   Updated: 2022/01/27 05:27:29 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include "dynarray.h"
#include "get_next_line.h"

typedef struct	s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				height;
	int				width;
	int				x;
	int				y;
}				t_mlx_data;

int	ft_get_map_ret(int *ret, int fd, char **s);
int	ft_verif_path(char *path);
int	ft_strcmp(char *str, char *str2);
