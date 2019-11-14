/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:30:14 by jkuusist          #+#    #+#             */
/*   Updated: 2019/10/31 13:57:02 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*charsrc;
	char	*chardst;
	size_t	i;

	charsrc = (char*)src;
	chardst = (char*)dst;
	if (src == dst)
		return (dst);
	if (chardst < charsrc)
	{
		i = 0;
		while (i < len)
		{
			chardst[i] = charsrc[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
			chardst[i] = charsrc[i];
	}
	return (dst);
}
