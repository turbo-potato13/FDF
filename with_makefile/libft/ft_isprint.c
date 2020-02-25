/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:02:36 by sverona           #+#    #+#             */
/*   Updated: 2019/09/10 21:03:55 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int chr)
{
	if (chr >= 32 && chr <= 126)
		return (chr);
	else
		return (0);
}