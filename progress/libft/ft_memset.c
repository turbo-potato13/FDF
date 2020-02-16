/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:45:28 by sverona           #+#    #+#             */
/*   Updated: 2019/09/17 20:30:50 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*a;

	i = 0;
	if (len == 0)
		return (b);
	a = (unsigned char*)b;
	while (len--)
	{
		a[i] = c;
		if (len)
			i++;
	}
	return (a);
}
