/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:43:26 by sverona           #+#    #+#             */
/*   Updated: 2019/09/17 20:37:27 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *des, const char *src, size_t n)
{
	size_t	i;
	int		k;

	k = 0;
	i = 0;
	while (des[k] != '\0')
		k++;
	while (i < n && src[i] != '\0')
	{
		des[k] = src[i];
		i++;
		k++;
	}
	des[k] = '\0';
	return (des);
}
