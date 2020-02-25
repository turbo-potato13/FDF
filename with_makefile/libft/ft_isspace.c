/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:15:19 by sverona           #+#    #+#             */
/*   Updated: 2019/09/18 18:36:04 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(const char s1)
{
	if (s1 == 32 || (s1 > 8 && s1 < 14))
		return (1);
	else
		return (0);
}