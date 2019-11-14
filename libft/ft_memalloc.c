/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:53:33 by jkuusist          #+#    #+#             */
/*   Updated: 2019/10/31 10:53:55 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	if (size == 0)
		return (0);
	res = (unsigned char*)(malloc(size));
	if (!res)
		return (0);
	while (i < size)
	{
		res[i] = 0;
		i++;
	}
	return ((void*)res);
}
