/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:08:24 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/07 12:17:55 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	if (!s1 || !s2)
		return (0);
	res = (char*)(malloc(sizeof(char*) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!res)
		return (0);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	return (res);
}
