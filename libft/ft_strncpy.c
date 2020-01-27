/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:00:07 by sverona           #+#    #+#             */
/*   Updated: 2019/09/17 20:32:33 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *des, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		des[i] = '\0';
		i++;
	}
	i = 0;
	while (i < n && src[i] != '\0')
	{
		des[i] = src[i];
		i++;
	}
	return (des);
}
