/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:45:11 by sverona           #+#    #+#             */
/*   Updated: 2019/09/17 20:30:19 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *msrc1, const void *msrc2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)msrc1;
	str2 = (unsigned char *)msrc2;
	if (n == 0)
		return (0);
	i = 0;
	while (n != 0 && str1[i] == str2[i])
	{
		i++;
		n--;
	}
	if (n == 0)
		i--;
	return (str1[i] - str2[i]);
}
