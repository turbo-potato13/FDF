/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:20:20 by sverona           #+#    #+#             */
/*   Updated: 2019/09/17 20:32:04 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	l;

	i = 0;
	k = 0;
	l = 0;
	while (dst[i] != '\0')
		i++;
	while (src[k] != '\0')
		k++;
	if (size <= i)
		k += size;
	else
		k += i;
	while (src[l] != '\0' && i + 1 < size)
	{
		dst[i] = src[l];
		l++;
		i++;
	}
	dst[i] = '\0';
	return (k);
}
