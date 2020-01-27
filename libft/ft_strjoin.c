/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:20:28 by sverona           #+#    #+#             */
/*   Updated: 2019/09/18 18:23:33 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	lin;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		new[len] = s1[len];
		len++;
	}
	lin = 0;
	while (s2[lin] != '\0')
	{
		new[len] = s2[lin];
		len++;
		lin++;
	}
	new[len] = '\0';
	return (new);
}
