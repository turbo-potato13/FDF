/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:46:39 by sverona           #+#    #+#             */
/*   Updated: 2019/09/18 17:57:55 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	n;

	new = (char *)malloc(sizeof(char) * size + 1);
	if (!new)
		return (NULL);
	n = 0;
	ft_bzero(new, size + 1);
	return (new);
}
