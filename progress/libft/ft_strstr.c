/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:42:54 by sverona           #+#    #+#             */
/*   Updated: 2019/09/18 16:39:32 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	char	*s;
	size_t	l1;
	size_t	l2;

	s = (char *)str1;
	l1 = ft_strlen(str1);
	l2 = ft_strlen(str2);
	while (l1 >= l2)
	{
		if (!ft_strncmp(s, str2, l2))
			return (s);
		else
			s++;
		l1--;
		if (l1 == l2 && !(ft_strcmp(s, str2)))
			return (s);
	}
	return (NULL);
}
