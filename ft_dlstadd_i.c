/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 21:09:05 by y0ja              #+#    #+#             */
/*   Updated: 2014/11/14 23:30:10 by y0ja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_i(t_dlist **list, t_dlist *lst_new, unsigned int n)
{
	t_dlist			*nav;
	unsigned int	i;
	unsigned int	len;

	nav = *list;
	i = 1;
	len = ft_dlstlen(*list);
	if (n >= len)
		ft_dlstadd_end(list, lst_new);
	else if (n == 0)
		ft_dlstadd(list, lst_new);
	else
	{
		while (i < n)
		{
			nav = nav->next;
			i++;
		}
		lst_new->next = nav->next;
		lst_new->next->before = lst_new;
		lst_new->before = nav;
		nav->next = lst_new;
	}
}
