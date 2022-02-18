/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:09:48 by ngenadie          #+#    #+#             */
/*   Updated: 2022/02/18 01:45:20 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_H
# define FT_SO_LONG_H

# include <stdio.h>
# include "mlx.h"
# include "dynarray.h"
# include "get_next_line.h"

# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define ESC 65307

typedef struct s_mlx_data
{
	t_dynarray		*darr;
	void			*mlx;
	void			*win;
	void			*img_ptr;
	int				height;
	int				width;
	int				nb_player;
	int				nb_exit;
	int				nb_collectibles;
	int				x;
	int				y;
	int				nb_collected;
	uint64_t		i;
	uint64_t		j;
	uint64_t		moves;
	void			*big_img_ptr;
}				t_mlx_data;

void	ft_print_darr(t_dynarray darr);
int		ft_get_map_ret(int *ret, int fd, char **s);
int		ft_verif_path(char *path);
int		ft_strcmp(char *str, char *str2);
void	ft_free_all(t_dynarray *darr);
void	ft_free(char *s);
int		ft_verif_closed_rect(t_dynarray *darr);
int		ft_count_obj(char *s, t_mlx_data *data);
void	ft_move_right(t_mlx_data *data, t_dynarray *darr);
void	ft_move_up(t_mlx_data *data, t_dynarray *darr);
void	ft_move_left(t_mlx_data *data, t_dynarray *darr);
void	ft_move_down(t_mlx_data *data, t_dynarray *darr);
void	ft_collect(t_mlx_data *data, t_dynarray *darr, uint64_t i, uint64_t j);
void	ft_walk(t_mlx_data *data, t_dynarray *darr, uint64_t i, uint64_t j);
void	ft_exit(t_mlx_data *data);
int		ft_close_win(t_mlx_data *data);
void	ft_player_coord(t_mlx_data *data, t_dynarray *darr);
void	ft_move(t_mlx_data *data, t_dynarray *darr, uint64_t i, uint64_t j);
int		ft_key_hook(int key, t_mlx_data *data);
int		ft_draw_board(t_mlx_data data, t_dynarray darr);
int		ft_draw_square(t_mlx_data data, char *path_string, int i, int j);
int		ft_verif_map(char *s);
int		ft_get_map(char **argv, t_dynarray *darr, t_mlx_data *data);
int		ft_verif_closed_rect2(t_dynarray *darr, char **map, int i, uint64_t j);
int		ft_draw(t_mlx_data data, char **board, uint64_t i, uint64_t j);
void	ft_print_error(void);
int		display(t_mlx_data *data, t_dynarray *darr, char **argv);
void	ft_putnbr(int pid);

#endif
