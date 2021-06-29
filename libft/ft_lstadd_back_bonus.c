/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:31:48 by fballest          #+#    #+#             */
/*   Updated: 2019/12/02 14:21:25 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*res;

	res = *alst;
	if (!(*alst))
		*alst = new;
	else
	{
		while (res->next)
			res = res->next;
		res->next = new;
		new = new->next;
	}
}
