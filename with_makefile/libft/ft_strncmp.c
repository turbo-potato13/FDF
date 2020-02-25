/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:46:05 by sverona           #+#    #+#             */
/*   Updated: 2019/09/17 20:32:37 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	i = 0;
	if (num == 0)
		return (0);
	while (i < num && str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
		i++;
	if (i == num)
		i--;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
