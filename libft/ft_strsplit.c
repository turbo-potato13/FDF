/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sverona <sverona@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:02:28 by sverona           #+#    #+#             */
/*   Updated: 2019/09/18 18:34:14 by sverona          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordam(char const *s, char c)
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

static void		ft_allfree(char **split, size_t i)
{
	while (i > 0)
	{
		ft_strdel(&split[i]);
		i--;
	}
	ft_strdel(split);
}

static char		**ft_str(char **split, char const *s, char c, int m)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if (n == 1)
			break ;
		s += (j + m);
		m = 0;
		while (*s == c && *s != '\0' && ++j)
			s++;
		while (*s != c && *s != '\0' && ++m)
			s++;
		if (*(s - 1) != c)
		{
			if (*s == '\0')
				n = 1;
			if (!(split[i++] = ft_strsub((s -= (j + m)), j, m)))
				ft_allfree(split, i - 1);
		}
	}
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		n;

	if (!s || !c)
		return (NULL);
	n = ft_wordam(s, c);
	split = (char**)malloc(sizeof(char*) * (n + 1));
	if (!split)
		return (NULL);
	if (n == 0)
	{
		*split = 0;
		return (split);
	}
	i = 0;
	split = ft_str(split, s, c, i);
	if (!split)
		return (NULL);
	split[n] = 0;
	return (split);
}
