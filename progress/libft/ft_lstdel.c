/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:09:23 by sverona           #+#    #+#             */
/*   Updated: 2019/09/16 17:52:36 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*al;
	t_list	*al1;

	al = *alst;
	while (al)
	{
		al1 = al->next;
		(del)(al->content, al->content_size);
		free(al);
		al = al1;
	}
	*alst = NULL;
}
