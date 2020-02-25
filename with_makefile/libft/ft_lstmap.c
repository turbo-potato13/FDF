/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:38:42 by sverona           #+#    #+#             */
/*   Updated: 2019/09/16 20:12:35 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lnew;
	t_list	*l;

	if (!lst)
		return (NULL);
	l = (f)(lst);
	lnew = l;
	while (lst->next)
	{
		lst = lst->next;
		l->next = (f)(lst);
		if (!(l->next))
		{
			free(l->next);
			return (NULL);
		}
		l = l->next;
	}
	return (lnew);
}
