/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:18:12 by sverona           #+#    #+#             */
/*   Updated: 2019/09/17 20:19:11 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n == 0)
		len++;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*it;
	int		l;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = ft_len(n);
	it = (char *)malloc(sizeof(char) * (l + 1));
	if (!it)
		return (NULL);
	if (n < 0)
	{
		it[0] = '-';
		n *= -1;
	}
	if (n == 0)
		it[0] = 48;
	it[l--] = '\0';
	while (n > 0)
	{
		it[l] = n % 10 + 48;
		n = n / 10;
		l--;
	}
	return (it);
}
