/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:35:26 by sverona           #+#    #+#             */
/*   Updated: 2020/02/26 16:33:11 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lint		*ft_get_coords(char *line, int fd, t_fdf_list fdf_list)
{
	t_lint	*listhead;
	char	**stroka;
	int		x;
	int		y;
	int		content;

	listhead = NULL;
	y = 0;
	while (get_next_line(fd, &line))
	{
		stroka = ft_strsplit(line, ' ');
		x = 0;
		while (stroka[x])
		{
			content = ft_atoi(stroka[x]);
			ft_lintadd(&listhead, ft_lintnew(content));
			x++;
		}
		y++;
	}
	printf ("i = %d\n", x);
	ft_lintadd(&listhead, ft_lintnew(y));
	return (listhead);
}

t_point		**ft_coord_mas(t_lint *listhead, int x, t_fdf_list fdf_list)
{
	t_lint		*tmt;
	t_point		**mas;
	int		i;
	int		y;
	int		f;

	y = listhead->content;
	mas = (t_point **)malloc((y + 1)  * sizeof(t_point *));
	listhead = listhead->next;
	mas[y] = NULL;
	i = x - 1;
	f = y - 1;
	while (y > 0)
	{
		y--;
		mas[y] = (t_point *)malloc(x * sizeof(t_point));
		while (i >= 0)
		{
			mas[y][i].x = i;
			mas[y][i].y = y;
			mas[y][i].z = listhead->content;
			mas[y][i].last = 0;
			listhead = listhead->next;
			i--;
		}
		i = x - 1;
		mas[y][i].last = 1;
	}
	return (mas);
}

void		ft_draw(t_fdf_list fdf_list, char *line, int fd)
{
	t_point	**mas;
	t_lint	*listhead;
	t_lint	*tmt;
	int x;
	int y;

	listhead = ft_get_coords(line, fd, fdf_list);
	x = 0;
	tmt = listhead;
	while(tmt)
	{
		x++;
		tmt = tmt->next;
	}
	x /= listhead->content;
	mas = ft_coord_mas(listhead, x, fdf_list);
	y = 0;
	while (mas[y])
	{
		x = 0;
		while(1)
		{
			if (mas[y + 1])
			{
				bresen(mas[y][x], mas[y + 1][x], fdf_list);
				//printf("x = %f, y = %f z = %f\n", mas[y + 1][x].x, mas[y + 1][x].y, mas[y + 1][x].z);
			}
			if (!mas[y][x].last)
			{
				bresen(mas[y][x], mas[y][x + 1], fdf_list);
				//printf("x = %f, y = %f z = %f\n", mas[y][x + 1].x, mas[y][x + 1].y, mas[y][x + 1].z);
			}
			if (mas[y][x].last)
				break;
			x++;
		}
		//printf("y = %d, x = %d, mas[y][x].x = %f mas[y][x].y = %f\n", y, x, mas[y][x].x, mas[y][x].y);
		y++;
	}

}
