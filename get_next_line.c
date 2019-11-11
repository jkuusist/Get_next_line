/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:33:55 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/11 10:47:17 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
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
		if (ret < 0)
			return (-1);
		buffer[ret] = '\0';
		if (store[fd] == NULL)
		{
			store[fd] = ft_strdup(buffer);
		}
		else
		{
			temp = ft_strjoin(store[fd], buffer);
			free(store[fd]);
			store[fd] = temp;
		}
		if (ft_strchr(store[fd], '\n'))
			break ;
	}	
	while ((*(store[fd]) != '\0') && (*(store[fd]) != '\0'))
		(store[fd])++;
	if (*(store[fd]) == '\n')
	{
		*line = ft_strsub((*store), 0, i);
		temp = ft_strdup(&((*store)[i + 1]));
		free (*store);
		*store = temp;
		if ((*store)[0] == '\0')
			ft_strdel(store);
	}
	else
	{
		*line = ft_strdup(store[fd]);
		ft_strdel(store);
	}
	return (1);
}
