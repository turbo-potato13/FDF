/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:24:06 by sverona           #+#    #+#             */
/*   Updated: 2020/02/07 13:26:07 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 2)
	{
		printf("Usage %s <filename>\n", argv[0]);
		return (1);
	}
	int f = 0;
	int i = 1;
	while (i < argc)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{	
			printf("%s\n", line);
			free(line);
			f++;
		}
		printf("= %i =/n", f);
		
		close(fd);
		i++;
	}

	return (0);
}
