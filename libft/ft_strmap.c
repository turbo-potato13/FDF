/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:39:38 by sverona           #+#    #+#             */
/*   Updated: 2019/09/18 18:07:54 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		l;
	char	*stmap;

	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	stmap = (char *)malloc(sizeof(char) * (l + 1));
	if (!stmap)
		return (NULL);
	l = 0;
	while (s[l] != '\0')
	{
		stmap[l] = (*f)(s[l]);
		l++;
	}
	stmap[l] = '\0';
	return (stmap);
}
