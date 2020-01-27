/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:59:03 by sverona           #+#    #+#             */
/*   Updated: 2019/09/17 20:32:52 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int smb)
{
	char	*sstt;
	char	*ew;
	int		i;
	int		f;

	sstt = (char *)str;
	ew = (char *)str;
	i = 0;
	f = 0;
	while (*sstt != '\0')
	{
		if (*sstt == smb)
		{
			f = 1;
			ew = sstt;
		}
		sstt++;
	}
	if (f == 0 && smb == '\0')
		return (sstt);
	if (f == 0)
		return (NULL);
	return (ew);
}
