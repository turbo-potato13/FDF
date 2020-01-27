/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:29:36 by sverona           #+#    #+#             */
/*   Updated: 2020/01/27 21:56:50 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "include/FdF.h"

void	ft_plot(t_fdf_list fdf_list, int x, int y)
{
	int i;

	i = x * fdf_list.bpp/8 + y * fdf_list.size_line;
	fdf_list.img_g[i + 2] = 255;
	mlx_put_image_to_window(fdf_list.mlx_ptr, fdf_list.win_ptr, fdf_list.img_ptr, 50, 50);
	
	
}

void	ft_line(t_fdf_list fdf_list, t_coord_list coord_list)
{
	int	d;
	int	d1;
	int	d2;
	int	x0;
	int	x1;

	while (coord_list.x0 < coord_list.x1)
	{
		coord_list.x0++;
		d = (2 * (coord_list.y1 - coord_list.y0) - (coord_list.x1 - coord_list.x0));
		d1 = 2 * (coord_list.y1 - coord_list.y0);
		d2 = ((coord_list.y1 - coord_list.y0) - (coord_list.x1 - coord_list.x0)) * 2;
		if (d < 0)
			d += d1;
		else
		{
			coord_list.y0++;
			d += d2;
		}
		ft_plot(fdf_list, coord_list.x0, coord_list.y0);
	}
}



int		main()
{
	t_fdf_list	fdf_list;
	t_coord_list	coord_list;
	//int		i;
	//int		x;
	//int		y;

	//x = 0;
	fdf_list.mlx_ptr = mlx_init();
	fdf_list.win_ptr = mlx_new_window(fdf_list.mlx_ptr, 500, 500, "mlx_42");
	fdf_list.img_ptr = mlx_new_image(fdf_list.mlx_ptr, 250, 250);
	fdf_list.img_g = mlx_get_data_addr(fdf_list.img_ptr, &fdf_list.bpp, &fdf_list.size_line, &fdf_list.endian);
	printf("%d %d %d\n", fdf_list.bpp, fdf_list.size_line, fdf_list.endian);

	//i = x * fdf_list.bpp/8 + y * fdf_list.size_line;
	//fdf_list.img_g[i] = 88;
	//fdf_list.img_g[i + 2] = 255;

	coord_list.x0 = 0;
	coord_list.x1 = 100;
	coord_list.y0 = 0;
	coord_list.y1 = 100;
	//ft_line(fdf_list, coord_list);
	ft_line(fdf_list, coord_list);
	//mlx_put_image_to_window(fdf_list.mlx_ptr, fdf_list.win_ptr, fdf_list.img_ptr, 50, 50);
	mlx_loop(fdf_list.mlx_ptr);
}