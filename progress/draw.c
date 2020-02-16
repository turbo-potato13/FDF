/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 23:19:15 by sverona           #+#    #+#             */
/*   Updated: 2020/02/16 23:21:25 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FdF.h"

void	ft_plot(t_fdf_list fdf_list, float x, float y)
{
	int i;

	i = x * fdf_list.bpp/8 + y * fdf_list.size_line;
	fdf_list.img_g[i + 2] = 255;
	fdf_list.img_g[i] = 155;
	mlx_put_image_to_window(fdf_list.mlx_ptr, fdf_list.win_ptr, fdf_list.img_ptr, 50, 50);
	//mlx_pixel_put(fdf_list.mlx_ptr, fdf_list.win_ptr, x, y, 0xffffff);
}

void	ft_line(t_fdf_list fdf_list, t_point point1, t_point point2)
{
	t_point	delta;
	float	e;
	float	e2;
	float	sx;
	float	sy;
	
	point1.x *=13;
	point2.x *=13;
	point1.y *=13;
	point2.y *=13;

	//iso(&point1.x, &point1.y, point1.z);
	//iso(&point2.x, &point2.y, point2.z);
	delta.x = fabsf(point1.x - point2.x);
	delta.y = fabsf(point2.y - point1.y);
	sx = (point1.x < point2.x) ? 1 : -1;
	sy = (point1.y < point2.y) ? 1 : -1;
	e = delta.x - delta.y;
	
	ft_plot (fdf_list, point2.x, point2.y);
	while (point1.x != point2.x || point1.y != point2.y)
	{
		ft_plot (fdf_list, point1.x, point1.y);
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
	}
}