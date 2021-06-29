/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 09:19:25 by fballest          #+#    #+#             */
/*   Updated: 2021/03/05 11:30:06 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libft.h"

static int	ft_intlen(int nb)
{
	int		len;
	long	num;

	num = nb;
	len = 1;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num >= 10)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		i;

	i = 0;
	nbr = n;
	str = (char *)malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	str[ft_intlen(n) - i] = '\0';
	while (nbr >= 10)
	{
		i++;
		str[ft_intlen(n) - i] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	i = i + 1;
	str[ft_intlen(n) - i] = (nbr % 10) + 48;
	return (str);
}
