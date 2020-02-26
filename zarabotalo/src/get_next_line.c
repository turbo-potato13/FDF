/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:48:14 by sverona           #+#    #+#             */
/*   Updated: 2020/02/25 19:00:29 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_list			*ft_listfind(int fd, t_list *listhead)
{
	while (listhead)
	{
		if ((int)listhead->content_size == fd)
			return (listhead);
		listhead = listhead->next;
	}
	return (NULL);
}

int				ft_list(char *p, char **line, t_list *nen, int ret)
{
	if (ret < 0 || line == NULL)
		return (-1);
	if (nen->content == NULL)
		return (0);
	if (p && *p)
	{
		*line = ft_strndup(nen->content, p - (char *)nen->content);
		p = ft_strdup(p + 1);
		ft_memdel(&nen->content);
		nen->content = p;
		return (1);
	}
	if (nen->content && *(char *)nen->content)
	{
		*line = ft_strdup(nen->content);
		ft_memdel(&nen->content);
		nen->content = ft_strnew(1);
		return (1);
	}
	return (0);
}

static t_list	*ft_listhead(int fd)
{
	t_list	*listhead;

	listhead = ft_lstnew("\0", 1);
	listhead->content_size = fd;
	return (listhead);
}

t_list			*ft_listnen(t_list **listhead, int fd)
{
	ft_lstadd(listhead, ft_lstnew("\0", 1));
	(*listhead)->content_size = fd;
	return (*listhead);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static t_list	*listhead;
	t_list			*nen;
	char			*pstr;

	if (fd < 0 || fd > 10240 || line == NULL ||
		read(fd, NULL, 0) == -1 || BUFF_SIZE <= 0)
		return (-1);
	if (!listhead)
		listhead = ft_listhead(fd);
	if (!(nen = ft_listfind(fd, listhead)))
		nen = ft_listnen(&listhead, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		pstr = nen->content;
		nen->content = nen->content == NULL ? ft_strdup(buf) :
						ft_strjoin(nen->content, buf);
		ft_strdel(&pstr);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	pstr = ft_strchr(nen->content, '\n');
	return (ft_list(pstr, line, nen, ret));
}
