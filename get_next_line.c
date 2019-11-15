/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:33:55 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/15 14:10:28 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int		write_line(char **store, char **line, char *temp, int fd)
{
	int i;

	i = 0;
	while ((store[fd][i] != '\n') && ((store[fd][i] != '\0')))
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

static int		get_return_value(char **store, int ret, int fd)
{
	if ((ret == 0) && (store[fd] == NULL))
		return (0);
	else
		return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*store[FD_MAX];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
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
		{
			temp = ft_strjoin(store[fd], buffer);
			free(store[fd]);
			store[fd] = temp;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if ((result = get_return_value(store, ret, fd)) != 0)
		result = write_line(store, line, temp, fd);
	return (result);
}
