/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:33:55 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/13 12:09:25 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static void		write_line_store(char **store, char *buffer, char *temp, int fd)
{
	if (store[fd] == NULL)
		store[fd] = ft_strdup(buffer);
	else
	{
		temp = ft_strjoin(store[fd], buffer);
		free(store[fd]);
		store[fd] = temp;
	}
	if (ft_strchr(buffer, '\n'))
		return ;
}

int				get_next_line(const int fd, char **line)
{
	static char	*store[STORE_SIZE];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			ret;
	int			i;

	if ((fd == -1) || (!line))
		return (-1);
	i = 0;
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		write_line_store(store, buffer, temp, fd);
	}
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
		ft_strdel(store);
	}
	return (1);
}
