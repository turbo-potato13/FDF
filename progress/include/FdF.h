/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:55:04 by sverona           #+#    #+#             */
/*   Updated: 2020/02/16 19:11:02 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include "../libft/libft.h"
#include "../g_n_l/get_next_line.h"

#ifndef FDF_H
# define FDF_H

typedef struct		s_fdf_list
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_g;
	int				bpp;
	int				size_line;
	int				endian;
}					t_fdf_list;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
}					t_point;

typedef struct		s_lint
{
	int				content;
	struct s_lint	*next;
}					t_lint;

t_lint	*ft_lintnew(int const content);
void	ft_lintadd(t_lint **alst, t_lint *new);
int		*ft_coord_mas(t_lint *listhead);
t_lint	*ft_get_coords(char *line, int fd);
void	ft_draw(int	*mas, t_fdf_list fdf_list);
void	ft_line(t_fdf_list fdf_list, t_point point1, t_point point2);

#endif