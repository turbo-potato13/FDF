/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:29:36 by sverona           #+#    #+#             */
/*   Updated: 2020/02/20 17:33:09 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FdF.h"

int		main(int argc, char **argv)
{
	t_fdf_list	fdf_list;
	t_point		point1;
	t_point		point2;
	t_point		point;
	int			y;
	int			fd;
	char		*line;
	t_lint		*kek;

	fdf_list.mlx_ptr = mlx_init();
	fdf_list.win_ptr = mlx_new_window(fdf_list.mlx_ptr, 1000, 1000, "fdf");
	fdf_list.img_ptr = mlx_new_image(fdf_list.mlx_ptr, 1000, 1000);
	fdf_list.img_g = mlx_get_data_addr(fdf_list.img_ptr, &fdf_list.bpp, &fdf_list.size_line, &fdf_list.endian);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		kek = ft_get_coords(line, fd);
		close(fd);
	}
	int *e;
	e = ft_coord_mas(kek);
	y = 0;
	printf(" %d \n", e[0]);
	printf(" %d \n", e[1]);
	printf(" %d \n", e[210]);
	printf(" = %d =\n", y);

	printf("%d %d %d\n", fdf_list.bpp, fdf_list.size_line, fdf_list.endian);


	//point1.y = 100;
	//point2.y = 100;
	////ft_line(fdf_list, coord_list);
	//ft_line(fdf_list, point1, point2);
	ft_draw(e, fdf_list);
	//mlx_put_image_to_window(fdf_list.mlx_ptr, fdf_list.win_ptr, fdf_list.img_ptr, 50, 50);
	mlx_loop(fdf_list.mlx_ptr);
}