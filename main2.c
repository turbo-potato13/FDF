/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:29:36 by sverona           #+#    #+#             */
/*   Updated: 2020/02/03 19:15:03 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "include/FdF.h"

void	ft_plot(t_fdf_list fdf_list, float x, float y)
{
	int i;

	i = x * fdf_list.bpp/8 + y * fdf_list.size_line;
	fdf_list.img_g[i + 2] = 255;
	mlx_put_image_to_window(fdf_list.mlx_ptr, fdf_list.win_ptr, fdf_list.img_ptr, 50, 50);
	
	
}

void	ft_line(t_fdf_list fdf_list, t_point point1, t_point point2)
{
	t_point	delta;
	float	e;
	float	e2;
	float	sx;
	float	sy;

	delta.x = abs(point1.x - point2.x);
	delta.y = abs(point2.y - point1.y);
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



int		main()
{
	t_fdf_list	fdf_list;
	t_point	point1;
	t_point	point2;

	//x = 0;
	fdf_list.mlx_ptr = mlx_init();
	fdf_list.win_ptr = mlx_new_window(fdf_list.mlx_ptr, 500, 500, "mlx_42");
	fdf_list.img_ptr = mlx_new_image(fdf_list.mlx_ptr, 250, 250);
	fdf_list.img_g = mlx_get_data_addr(fdf_list.img_ptr, &fdf_list.bpp, &fdf_list.size_line, &fdf_list.endian);
	printf("%d %d %d\n", fdf_list.bpp, fdf_list.size_line, fdf_list.endian);

	//i = x * fdf_list.bpp/8 + y * fdf_list.size_line;
	//fdf_list.img_g[i] = 88;
	//fdf_list.img_g[i + 2] = 255;

	point1.x = 0;
	point2.x = 100;
	point1.y = 100;
	point2.y = 100;
	//ft_line(fdf_list, coord_list);
	ft_line(fdf_list, point1, point2);
	//mlx_put_image_to_window(fdf_list.mlx_ptr, fdf_list.win_ptr, fdf_list.img_ptr, 50, 50);
	mlx_loop(fdf_list.mlx_ptr);
}