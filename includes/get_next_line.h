/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngenadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:19:44 by ngenadie          #+#    #+#             */
/*   Updated: 2022/01/27 00:50:19 by ngenadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int		get_next_line(int fd, char **s);
int		get_next_line2(char **str, char ***line, int nl_index, int len);
int		ft_nl_index(char *str);
int		ft_strlen(char *str);
char	*ft_realloc(char *str, char *buff, int len);
char	*ft_send_clean(char **s, char *str, int nl_index);
int		ft_one_line_malloc(char **str, int len);
int		ft_nl(int *nl_index, char *str);
int		ft_len(int *len, int fd, char *buff);

#endif
