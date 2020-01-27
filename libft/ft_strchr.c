/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:19:06 by sverona           #+#    #+#             */
/*   Updated: 2019/09/17 20:31:24 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int smb)
{
	char	q;
	int		i;
	char	*sstt;

	sstt = (char *)str;
	q = smb;
	i = 0;
	while (*sstt != q)
	{
		if (*sstt == '\0')
			return (NULL);
		sstt++;
	}
	return (sstt);
}
