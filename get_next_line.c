/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:33:55 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/18 15:02:38 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int		write_line(char **store, char **line, int fd)
{
	int		i;
	char	*temp;

	i = 0;
	while ((store[fd][i] != '\n') && (store[fd][i] != '\0'))
		i++;
	if (store[fd][i] == '\n')
	{
		*line = ft_strsub((store[fd]), 0, i);
		temp = ft_strdup(&((store[fd])[i + 1]));
		free(store[fd]);
		store[fd] = temp;
		if (store[fd][0] == '\0')
			ft_strdel(store);
	}
	else if (store[fd][0] == '\0')
		return (0);
	else
	{
		*line = ft_strdup(store[fd]);
		ft_strdel(&store[fd]);
	}
	return (1);
}

static void		handle_buffer(char **store, char *buffer, int fd)
{
	char *temp;

	temp = ft_strjoin(store[fd], buffer);
	free(store[fd]);
	store[fd] = temp;
}

static int		get_return_value(char **store, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if ((ret == 0) && (store[fd] == NULL))
		return (0);
	else
		return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*store[FD_MAX];
	char		buffer[BUFF_SIZE + 1];
	int			ret;
	int			result;

	if ((fd == -1) || (!line))
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (store[fd] == NULL)
			store[fd] = ft_strdup(buffer);
		else
			handle_buffer(store, buffer, fd);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if ((result = get_return_value(store, ret, fd)) != 0)
		result = write_line(store, line, fd);
	return (result);
}
