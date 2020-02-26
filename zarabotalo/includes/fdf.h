/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:55:04 by sverona           #+#    #+#             */
/*   Updated: 2020/02/26 14:34:15 by sverona          ###   ########.fr       */
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


#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 16

int get_next_line(const int fd, char **line);


typedef struct		s_fdf_list
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_g;
	int				bpp;
	int				size_line;
	int				endian;
	int				win_x;
	int				win_y;
}					t_fdf_list;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				last;
}					t_point;

typedef struct		s_lint
{
	int				content;
	struct s_lint	*next;
}					t_lint;

t_lint		*ft_lintnew(int const content);
void		ft_lintadd(t_lint **alst, t_lint *new);
t_point		**ft_coord_mas(t_lint *listhead, int x, t_fdf_list fdf_list);
t_lint		*ft_get_coords(char *line, int fd, t_fdf_list fdf_list);
void		ft_draw(t_fdf_list fdf_list, char *line, int fd);
void		ft_plot(t_fdf_list fdf_list, float x, float y);
void		ft_line(t_point point1, t_point point2, t_fdf_list fdf_list);
void		ft_iso(float *x, float *y, float z);
void		bresen(t_point point1, t_point point2, t_fdf_list fdf_list);

#endif