/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:35:26 by sverona           #+#    #+#             */
/*   Updated: 2020/02/16 19:49:30 by sverona          ###   ########.fr       */
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

void	ft_draw(int	*mas, t_fdf_list fdf_list)
{
	t_point	one;
	t_point	two;
	int	y;
	int	x;

	y = 0;
	printf("y = %d\n" , mas[1]);
	printf("x = %d\n" , (mas[0] / mas[1]));
	while (y < mas[1])
	{
		x = 0;
		while (x < (mas[0] / mas[1]))
		{
			if (x % 2)
			{
				one.x = x;
				one.y = y;
				one.z = mas[x + y * 10];
			}
			else
			{
				two.x = x;
				two.y = y;
				two.z = mas[x + y * 10];
			}
			ft_line(fdf_list, one, two);
			x++;
		}
		y++;
	}
}

