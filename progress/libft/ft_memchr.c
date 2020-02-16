/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:48:47 by sverona           #+#    #+#             */
/*   Updated: 2019/09/17 20:30:03 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int val, size_t n)
{
	int				i;
	unsigned char	*sstt;

	sstt = (unsigned char *)str;
	i = 0;
	while (n != 0)
	{
		if (*sstt == (unsigned char)val)
			return (sstt);
		n--;
		sstt++;
	}
	return (NULL);
}
