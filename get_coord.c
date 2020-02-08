/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:29:55 by sverona           #+#    #+#             */
/*   Updated: 2020/02/08 21:21:22 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FdF.h"

int     heavy(t_point heavyweight, char *filename)
{
    int heavy;
    int fd;
    char *line;

    heavy = 0;
    fd =  open(filename, O_RDONLY);
    while (get_next_line(fd, &line))
    {
        heavy++;
        free(line);
    }
    close(fd);
    return (heavy);
}

int     weight(t_point heavyweight, char *filename)
{
    int weight;
    int fd;
    char *line;

    fd =  open(filename, O_RDONLY);
    get_next_line(fd, &line);
    weight = ft_wordam(line, ' ');
    free(line);
    close(fd);
    return (weight);
}

int		main(int argc, char **argv)
{
    t_point heavyweight;
    int i;
    int **mas;

    mas = (int**)malloc(sizeof(int*) * (weight(heavyweight, argv[1]) + 1));

    if (argc == 2)
    {
        printf("heavy = %d\n", heavy(heavyweight, argv[1]));
        printf("weight = %d\n", weight(heavyweight, argv[1]));
    }
}
