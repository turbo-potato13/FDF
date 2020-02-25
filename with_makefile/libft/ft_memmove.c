/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:34:37 by sverona           #+#    #+#             */
/*   Updated: 2019/09/18 17:39:13 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *des, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*srci;

	if (!des && !src)
		return (NULL);
	dest = (unsigned char *)des;
	srci = (unsigned char *)src;
	if (n == 0)
		return (dest);
	if (srci == des)
		return (des);
	if (srci < dest)
	{
		srci = (unsigned char *)src + n - 1;
		dest = des + n - 1;
		while (n--)
			*dest-- = *srci--;
	}
	else
	{
		while (n--)
			*dest++ = *srci++;
	}
	return (des);
}
