/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:50:48 by sverona           #+#    #+#             */
/*   Updated: 2019/09/18 18:50:26 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		l;
	int		m;
	char	*str;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	i = -1;
	while (ft_isspace(s[l - 1]))
		l--;
	while (ft_isspace(s[++i]))
		l--;
	if (l <= 0)
		return (ft_strnew(0));
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	m = 0;
	while (m < l)
		str[m++] = s[i++];
	str[m] = '\0';
	return (str);
}
