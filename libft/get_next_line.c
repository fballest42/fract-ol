/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:07:09 by fballest          #+#    #+#             */
/*   Updated: 2021/03/15 14:41:02 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_delline(char **del)
{
	if (del != NULL && *del != NULL)
	{
		free(*del);
		*del = NULL;
	}
}

static int	ft_addline(char **aux, char **line, int fd)
{
	int		len;
	char	*tmp;

	len = 0;
	while (aux[fd][len] != '\n')
		len++;
	*line = ft_substr(aux[fd], 0, len);
	tmp = ft_strdup(&aux[fd][len + 1]);
	free(aux[fd]);
	aux[fd] = tmp;
	return (1);
}

static int	ft_salida(char **aux, char **line, int cnt, int fd)
{
	if (cnt < 0)
		return (-1);
	else if (cnt == 0 && (aux[fd] == NULL || aux[fd][0] == '\0'))
	{
		*line = ft_strdup("");
		ft_delline(&aux[fd]);
		return (0);
	}
	else if (ft_strchr(aux[fd], '\n'))
		return (ft_addline(aux, line, fd));
	else
	{
		*line = ft_strdup(aux[fd]);
		ft_delline(&aux[fd]);
		return (0);
	}
}

static void	ft_get_utils(int fd, char *buff, char **aux, char *tmp)
{
	if (aux[fd] == NULL)
		aux[fd] = ft_strdup(buff);
	else
	{
		tmp = ft_strjoin(aux[fd], buff);
		free(aux[fd]);
		aux[fd] = tmp;
	}
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*aux[4096];
	char		*tmp;
	int			cnt;

	tmp = NULL;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line || fd < 0 || BUFFER_SIZE < 1 || !buff)
		return (-1);
	cnt = read(fd, buff, BUFFER_SIZE);
	while (cnt > 0)
	{
		buff[cnt] = '\0';
		ft_get_utils(fd, buff, aux, tmp);
		if (ft_strchr(aux[fd], '\n'))
			break ;
		cnt = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (ft_salida(aux, line, cnt, fd));
}
