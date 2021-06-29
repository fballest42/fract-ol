/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 09:24:09 by fballest          #+#    #+#             */
/*   Updated: 2021/03/05 13:05:13 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

static int	ft_contar(char const *s, char c)
{
	int			wlen;
	size_t		w;

	wlen = 0;
	w = 0;
	while (*s)
	{
		if (!wlen && *s != c)
			w++;
		wlen = 1;
		if (*s == c)
			wlen = 0;
		s++;
	}
	return (w);
}

static int	ft_lenword(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_checkerstr(const char *s, char c, int j)
{
	while (s[j] == c)
		j++;
	return (j);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_contar(s, c) + 1));
	if (!str)
		return (NULL);
	while (++i < ft_contar(s, c))
	{
		k = 0;
		str[i] = ft_calloc(ft_lenword(&s[j], c) + 1, 1);
		if (!str[i])
			str[i] = NULL;
		j = ft_checkerstr(s, c, j);
		while (s[j] != c && s[j])
			str[i][k++] = s[j++];
		str[i][k] = '\0';
	}
	str[i] = 0;
	return (str);
}
