/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lintnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:22:06 by sverona           #+#    #+#             */
/*   Updated: 2020/02/16 18:48:43 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/FdF.h"

t_lint	*ft_lintnew(int const content)
{
	t_lint	*lnew;

	lnew = (t_lint *)malloc(sizeof(t_lint));
	if (!lnew)
		return (NULL);
	if (content)
	{
		lnew->content = content;
		lnew->next = NULL;
	}
	else
	{
		lnew->content = 0;
		lnew->next = NULL;
	}
	return (lnew);
}

void	ft_lintadd(t_lint **alst, t_lint *new)
{
	new->next = (*alst);
	*alst = new;
}
