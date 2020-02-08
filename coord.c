/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:29:27 by sverona           #+#    #+#             */
/*   Updated: 2020/02/08 20:24:49 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FdF.h"

t_point		*ft_new_point(t_point *point)
{
	t_point *new_point;

	new_point = (t_point *)malloc(sizeof(t_point));
	if (!new_point)
		return (NULL);
	point->next = new_point;
	return (new_point);
}

t_point		*ft_point_list(char **stroka, int y, t_point *best_point)
{
	t_point 		*point;
	int i;

	i = 1;
	point = (t_point *)malloc(sizeof(t_point));
	while (stroka[i] != NULL)
	{
		point->x = i;
		point->y = y;
		point->z = ft_atoi(stroka[i]);
		if(i == 1 && y == 1) 
        {
            best_point = point;
            return(ft_new_point(best_point));
        }
         else
            return(ft_new_point(point));
	    i++;
    }
        
}

int		main(int argc, char **argv)
{
	int		y;
	int		fd;
	char	*line;
    t_point *best_point;
	t_point *kek;
	char **stroka;

	y = 1;	
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			stroka = ft_strsplit(line, ' ');
			kek = ft_point_list(stroka, y, best_point);
			y++;
		}
        kek->next = NULL;
		close(fd);
	}
    fd = 0;
    while (best_point)
    {
        fd++;
        best_point = best_point->next;
    }
    printf("points = %d\n" , fd);
    return (0);
}