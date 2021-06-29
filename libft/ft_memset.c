/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:59:05 by fballest          #+#    #+#             */
/*   Updated: 2019/11/19 15:51:06 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char		*str;

	str = dest;
	while (n--)
	{
		*str = c;
		str++;
	}
	return (dest);
}
