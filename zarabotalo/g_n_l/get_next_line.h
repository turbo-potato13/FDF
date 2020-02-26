/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:05:29 by sverona           #+#    #+#             */
/*   Updated: 2020/02/07 14:39:32 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# include "../libft/libft.h"
# include <fcntl.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 16

int get_next_line(const int fd, char **line);

#endif
