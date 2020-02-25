/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:19:06 by sverona           #+#    #+#             */
/*   Updated: 2019/10/08 19:01:28 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int smb)
{
	int		i;
	char	*sstt;

	if (!str || !smb)
		return (NULL);
	sstt = (char *)str;
	i = 0;
	while (*sstt != smb)
	{
		if (*sstt == '\0')
			return (NULL);
		sstt++;
	}
	return (sstt);
}
