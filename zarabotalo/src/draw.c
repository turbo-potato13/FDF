/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:19:15 by sverona           #+#    #+#             */
/*   Updated: 2020/02/26 16:36:53 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_plot(t_fdf_list fdf_list, float x, float y)
{
	int i;

	i = x * fdf_list.bpp / 8 + y * fdf_list.size_line;
	fdf_list.img_g[i + 2] = 255;
	fdf_list.img_g[i] = 155;
	//mlx_pixel_put(fdf_list.mlx_ptr, fdf_list.win_ptr, x, y, 0xffffff);
}

static void iso(float *x, float *y, int z)
{
	float s_x;
	float s_y;
	
	s_x = *x;
	s_y = *y;
	*x = (s_x - s_y) * cos(0.523599);
	*y = -z + (s_x + s_y) * sin(0.523599);
}

t_point		ft_set_coord(t_point point, t_fdf_list fdf_list)
{
	point.x *= 20;
	point.y *= 20;
	point.z *= 1;
	iso(&point.x, &point.y, point.z);
	point.x += fdf_list.win_x / 3;
	point.y += fdf_list.win_y / 3;

	return(point);
}

void	ft_line(t_point point1, t_point point2, t_fdf_list fdf_list)
{
	t_point	delta;
	float	e;
	float	e2;
	float	sx;
	float	sy;
	int		i;
	
	point1 = ft_set_coord(point1, fdf_list);
	point2 = ft_set_coord(point2, fdf_list);
	delta.x = fabsf(point1.x - point2.x);
	delta.y = fabsf(point2.y - point1.y);
	sx = (point1.x < point2.x) ? 1 : -1;
	sy = (point1.y < point2.y) ? 1 : -1;
	e = delta.x - delta.y;
	//mlx_pixel_put(fdf_list.mlx_ptr, fdf_list.win_ptr, point2.x, point2.y, 0xffffff);
	while (((int)point1.x - (int)point2.x) || ((int)point1.y - (int)point2.y))
	{
		//ft_plot (fdf_list, point1.x, point1.y);
		i = point1.x * fdf_list.bpp / 8 + point1.y * fdf_list.size_line;
		fdf_list.img_g[i + 2] = 255;
		mlx_pixel_put(fdf_list.mlx_ptr, fdf_list.win_ptr, point1.x, point1.y, 0xffffff);
		e2 = e * 2;
		if (e2 > -delta.y)
		{
			e -= delta.y;
			point1.x += sx;
		}
		if (e2 < delta.x)
		{
			e += delta.x;
			point1.y += sy;
		}
		if (point1.x > 1000 || point1.y > 1000 || point1.y < 0 || point1.x < 0)
			break ;
	}
	
}

void		bresen(t_point point1, t_point point2, t_fdf_list fdf_list)
{
	float	x_step;
	float	y_step;
	int		max;
	int		color;
	int		i;

	point1 = ft_set_coord(point1, fdf_list);
	point2 = ft_set_coord(point2, fdf_list);

	x_step = point2.x - point1.x;
	y_step = point2.y - point1.y;
	max = (fabsf(x_step) > fabsf(y_step) ? fabsf(x_step) : fabsf(y_step));
	x_step /= max;
	y_step /= max;

	while ((int)(point1.x - point2.x) || (int)(point1.y - point2.y))
	{
		i = point1.x * fdf_list.bpp / 8 + point1.y * fdf_list.size_line;
		
		//mlx_pixel_put(fdf_list.mlx_ptr, fdf_list.win_ptr, point1.x, point1.y, 0xffffff);
		//ft_plot (fdf_list, point1.x, point1.y);
		point1.x += x_step;
		point1.y += y_step;
		if (point1.x > 1000 || point1.y > 1000 || point1.y < 0 || point1.x < 0)
			break ;
	}

}