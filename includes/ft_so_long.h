/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:09:48 by ngenadie          #+#    #+#             */
/*   Updated: 2022/02/04 00:39:54 by ngenadie         ###   ########.fr       */
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
	int				nb_player;
	int				nb_exit;
	int				nb_collectibles;
	int				x;
	int				y;
}				t_mlx_data;

void	ft_print_darr(t_dynarray darr);
int	ft_get_map_ret(int *ret, int fd, char **s);
int	ft_verif_path(char *path);
int	ft_strcmp(char *str, char *str2);
void	ft_free_all(t_dynarray *darr);
void	ft_free(char *s);
int	ft_verif_closed_rect(t_dynarray darr);
int	ft_count_obj(char *s, t_mlx_data *data);
