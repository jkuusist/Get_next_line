/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:25:30 by jkuusist          #+#    #+#             */
/*   Updated: 2019/10/29 16:04:01 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while ((haystack[i] != '\0') && (i <= (int)len))
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while ((haystack[i + j] == needle[j]) && ((i + j) < (int)len) &&
					(needle[j] != '\0'))
				j++;
			if (needle[j] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (0);
}
