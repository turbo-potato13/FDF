/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:52:57 by sverona           #+#    #+#             */
/*   Updated: 2019/09/18 18:07:44 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	l;
	char			*stmapi;

	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	stmapi = (char *)malloc(sizeof(char) * l + 1);
	if (!stmapi)
		return (NULL);
	l = 0;
	while (s[l] != '\0')
	{
		stmapi[l] = (*f)(l, s[l]);
		l++;
	}
	stmapi[l] = '\0';
	return (stmapi);
}
