/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:09:48 by ngenadie          #+#    #+#             */
/*   Updated: 2022/01/23 01:24:25 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"

typedef struct	mlx_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	unsigned int x;
	unsigned int y;
}				mlx_data;
