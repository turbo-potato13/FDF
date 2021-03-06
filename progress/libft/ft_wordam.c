/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:02:55 by sverona           #+#    #+#             */
/*   Updated: 2020/02/08 21:04:18 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wordam(char const *s, char c)
{
	int	n;

	n = 0;
	while (*s != '\0')
	{
		if (*s == c || (*(s - 1) != c && *(s - 1) != '\0'))
			s++;
		else
		{
			s++;
			n++;
		}
	}
	return (n);
}