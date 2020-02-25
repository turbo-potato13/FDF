/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:06:08 by sverona           #+#    #+#             */
/*   Updated: 2019/09/18 18:19:49 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*des;
	unsigned int	i;
	unsigned int	q;

	if (!s)
		return (NULL);
	i = start;
	q = 0;
	des = (char *)malloc(sizeof(char) * (len + 1));
	if (!des)
		return (NULL);
	while (q != len && s[i] != '\0')
	{
		des[q] = s[i];
		i++;
		q++;
	}
	des[q] = '\0';
	return (des);
}
