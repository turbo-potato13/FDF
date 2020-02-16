/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:35:26 by sverona           #+#    #+#             */
/*   Updated: 2020/02/16 23:00:37 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FdF.h"

t_lint		*ft_get_coords(char *line, int fd)
{
	t_lint	*listhead;
	char	**stroka;
	int		i;
	int		y;
	int		content;

	listhead = NULL;
	y = 0;
	while (get_next_line(fd, &line))
	{
		stroka = ft_strsplit(line, ' ');
		i = 0;
		while (stroka[i])
		{
			content = ft_atoi(stroka[i]);
			ft_lintadd(&listhead, ft_lintnew(content));
			i++;
		}
		y++;
	}
	ft_lintadd(&listhead, ft_lintnew(y));
	return (listhead);
}

int			*ft_coord_mas(t_lint *listhead)
{
	t_lint	*tmt;
	int		*mas;
	int		i;
	int		j;

	i = 0;
	tmt = listhead;
	while (tmt)
	{
		i++;
		tmt = tmt->next;
	}
	j = 0;
	mas = (int *)malloc((i + 1) * sizeof(int));
	mas[j] = i;
	while (j < i)
	{
		mas[++j] = (listhead->content);
		listhead = listhead->next;
	}
	return (mas);
}

static void iso(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void		ft_draw(int *mas, t_fdf_list fdf_list)
{
	t_point	one;
	t_point	two;
	int		y;
	int		x;
	int		z;

	y = 0;
	z = 2;
	while (y < mas[1])
	{
		x = 0;
		while (x < (mas[0] / mas[1]))
		{

			one.x = x;
			two.x = x + 1;
			one.y = y;
			two.y = y;
			one.z = mas[z];
			two.z = mas[z];
			ft_line(fdf_list, one, two);
			two.x = x;
			two.y = y + 1;
			ft_line(fdf_list, one, two);
			x++;
			if (z < 209)
				z++;
		}
		y++;
	}
}
