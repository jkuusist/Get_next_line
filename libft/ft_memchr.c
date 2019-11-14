/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:23:37 by jkuusist          #+#    #+#             */
/*   Updated: 2019/10/29 13:27:09 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*s1;

	i = 0;
	ch = (unsigned char)c;
	s1 = (unsigned char*)s;
	while (i < n)
	{
		if (s1[i] == ch)
		{
			return (s1 + i);
		}
		i++;
	}
	return (0);
}
