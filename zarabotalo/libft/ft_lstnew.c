/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:22:51 by sverona           #+#    #+#             */
/*   Updated: 2019/09/16 16:21:05 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lnew;

	lnew = (t_list *)malloc(sizeof(t_list));
	if (!lnew)
		return (NULL);
	if (content)
	{
		lnew->content = malloc(content_size);
		if ((lnew->content) == NULL)
		{
			free(lnew);
			return (NULL);
		}
		lnew->content_size = content_size;
		lnew->next = NULL;
		ft_memcpy((lnew->content), content, content_size);
	}
	else
	{
		lnew->content = NULL;
		lnew->content_size = 0;
		lnew->next = NULL;
	}
	return (lnew);
}
