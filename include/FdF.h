/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:55:04 by sverona           #+#    #+#             */
/*   Updated: 2020/01/27 21:27:38 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

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

typedef struct		s_coord_list
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
}					t_coord_list;

#endif