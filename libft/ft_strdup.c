/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:00:49 by sverona           #+#    #+#             */
/*   Updated: 2019/09/18 17:47:04 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*rts;

	i = ft_strlen(src);
	rts = (char*)malloc(sizeof(char) * (i + 1));
	if (!rts)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		rts[i] = src[i];
		i++;
	}
	rts[i] = '\0';
	return (rts);
}
