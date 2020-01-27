/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:04:52 by sverona           #+#    #+#             */
/*   Updated: 2019/09/18 16:52:09 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	char	*s;
	size_t	l1;
	size_t	l2;
	size_t	n;

	n = 0;
	s = (char *)str1;
	l1 = ft_strlen(str1);
	l2 = ft_strlen(str2);
	while (l1 >= l2 && n + l2 <= len)
	{
		if (!ft_strncmp(s, str2, l2))
			return (s);
		else
			s++;
		l1--;
		if (l1 == l2 && !(ft_strcmp(str1, str2)))
			break ;
		n++;
	}
	return (NULL);
}
