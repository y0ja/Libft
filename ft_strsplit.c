/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 22:00:07 by jripoute          #+#    #+#             */
/*   Updated: 2014/11/09 08:11:11 by jripoute         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		f_how_many_tab(char const *s, char c)
{
	int			how_many_tab;
	size_t		i;

	how_many_tab = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			how_many_tab++;
		if (s[i] == c)
		{
			if (s[i + 1] && s[i + 1] != c)
				how_many_tab++;
		}
		i++;
	}
	return (how_many_tab);
}

static void		create_tab(char const *s, char **tab, char c)
{
	size_t i;
	size_t j;
	size_t lenght;

	i = 0;
	j = 0;
	lenght = 0;
	while (s[i])
	{
		if ((s[i - 1] == c && s[i] && s[i] != c) || (i == 0 && s[i] != c))
		{
			lenght = ft_strclen(&s[i], c);
			if ((int)lenght == -1)
				lenght = ft_strclen(&s[i], '\0');
			tab[j] = (char *)ft_memalloc(sizeof(char) * lenght + 1);
			ft_strncpy(tab[j], &s[i], lenght);
			i += lenght;
			j++;
		}
		i++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	int			how_many_tab;
	char		**tab;

	if (!s || !c)
		return (NULL);
	how_many_tab = f_how_many_tab(s, c);
	tab = (char **)ft_memalloc(sizeof(tab) * how_many_tab + 1);
	create_tab(s, tab, c);
	tab[how_many_tab] = 0;
	return (tab);
}
