/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouvroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:53:48 by nrouvroy          #+#    #+#             */
/*   Updated: 2018/07/12 13:48:45 by nrouvroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_new_line(char **fdtab, char **line, int fd, int ret)
{
	char	*tmp;
	int		size;

	size = 0;
	while (fdtab[fd][size] != '\n' && fdtab[fd][size] != '\0')
		size++;
	if (fdtab[fd][size] == '\n')
	{
		*line = ft_strsub(fdtab[fd], 0, size);
		tmp = ft_strdup(fdtab[fd] + size + 1);
		free(fdtab[fd]);
		fdtab[fd] = tmp;
		if (fdtab[fd][0] == '\0')
			ft_strdel(&fdtab[fd]);
	}
	else if (fdtab[fd][size] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(fdtab[fd]);
		ft_strdel(&fdtab[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*fdtab[8192];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (fdtab[fd] == NULL)
			fdtab[fd] = ft_strnew(1);
		tmp = ft_strjoin(fdtab[fd], buf);
		free(fdtab[fd]);
		fdtab[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!fdtab[fd] || fdtab[fd][0] == '\0'))
		return (0);
	return (ft_new_line(fdtab, line, fd, ret));
}
