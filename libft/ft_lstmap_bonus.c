/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:08:29 by fballest          #+#    #+#             */
/*   Updated: 2021/03/04 11:06:47 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*dev;
	t_list		*new;
	t_list		*aux;

	if (!lst || !f)
		return (NULL);
	aux = lst;
	dev = ft_lstnew(f(aux->content));
	if (!dev)
		return (NULL);
	aux = aux->next;
	while (aux)
	{
		new = ft_lstnew(f(aux->content));
		if (!new)
		{
			ft_lstclear(&dev, del);
			return (NULL);
		}
		ft_lstadd_back(&dev, new);
		aux = aux->next;
	}
	return (dev);
}
