/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:23:16 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/07 12:03:38 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		is_whitespace(char c)
{
	if ((c == ' ') || (c == '\n') || (c == '\t'))
		return (1);
	else
		return (0);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*res;

	if (!s)
		return (0);
	start = 0;
	end = ft_strlen(s);
	i = 0;
	while (is_whitespace(s[start]))
		start++;
	while (s[end] == '\0')
		end--;
	while (is_whitespace(s[end]) && (end > 0))
		end--;
	if (!s || (start > end))
	{
		if (!(res = (char*)(malloc(sizeof(char) * (ft_strlen(s) + 1)))))
			return (0);
		res = ft_strcpy(res, "");
		return (res);
	}
	res = ft_strsub(s, start, ((end - start) + 1));
	return (res);
}
