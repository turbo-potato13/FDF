/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:50:32 by sverona           #+#    #+#             */
/*   Updated: 2019/10/02 18:24:44 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	char	*rts;

	if (!src || !*src)
		return (NULL);
	i = ft_strlen(src) < n ? ft_strlen(src) : n;
	rts = (char*)malloc(sizeof(char) * (i + 1));
	if (!rts)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && (i < n))
	{
		rts[i] = src[i];
		i++;
	}
	rts[i] = '\0';
	return (rts);
}
