/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:39:33 by sverona           #+#    #+#             */
/*   Updated: 2019/09/18 17:03:44 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *des, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (!des && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)des)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (des);
}
