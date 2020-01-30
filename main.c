/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:29:36 by sverona           #+#    #+#             */
/*   Updated: 2020/01/30 18:29:02 by sverona          ###   ########.fr       */
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
	float	d;
	float	d1;
	float	d2;
	float	x0;
	float	x1;

	if (point1.y > point2.y)
	{
		while (point1.x < point2.x)
		{	
			point1.x++;
			d = (2 * (point1.y - point2.y) - (point2.x - point1.x));
			d1 = 2 * (point1.y - point2.y);
			d2 = ((point1.y - point2.y) - (point2.x - point1.x)) * 2;
			if (d < 0)
				d += d1;
			else
			{
				point1.y--;
				d += d2;
			}
		ft_plot(fdf_list, point1.x, point1.y);
		}
		while (point1.x > point2.x)
		{
			point1.x--;
			d = (2 * (point1.y - point2.y) - (point2.x - point1.x));
			d1 = 2 * (point1.y - point2.y);
			d2 = ((point1.y - point2.y) - (point2.x - point1.x)) * 2;
			if (d < 0)
				d += d1;
			else
			{
				point1.y--;
				d += d2;
			}
			ft_plot(fdf_list, point1.x, point1.y);
		}
	}
	else
	{
		while (point1.x < point2.x)
		{
			point1.x++;
			d = (2 * (point2.y - point1.y) - (point2.x - point1.x));
			d1 = 2 * (point2.y - point2.y);
			d2 = ((point2.y - point1.y) - (point2.x - point1.x)) * 2;
			if (d < 0)
				d += d1;
			else
			{
				point1.y++;
				d += d2;
			}
			ft_plot(fdf_list, point1.x, point1.y);
		}
		while (point1.x > point2.x)
		{
			point1.x--;
			d = (2 * (point2.y - point1.y) - (point2.x - point1.x));
			d1 = 2 * (point2.y - point2.y);
			d2 = ((point2.y - point1.y) - (point2.x - point1.x)) * 2;
			if (d < 0)
				d += d1;
			else
			{
				point1.y++;
				d += d2;
			}
			ft_plot(fdf_list, point1.x, point1.y);
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

	point1.x = 100;
	point2.x = 0;
	point1.y = 100;
	point2.y = 0;
	//ft_line(fdf_list, coord_list);
	ft_line(fdf_list, point1, point2);
	//mlx_put_image_to_window(fdf_list.mlx_ptr, fdf_list.win_ptr, fdf_list.img_ptr, 50, 50);
	mlx_loop(fdf_list.mlx_ptr);
}