/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:14:06 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/05 12:32:44 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	wordcount(char const *s, char c)
{
	int i;
	int res;
	int state;

	i = 0;
	res = 0;
	state = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			res++;
		}
		i++;
	}
	return (res);
}

static int	wordlen(char const *s, char c)
{
	int res;

	res = 0;
	while ((*s != c) && (*s != '\0'))
	{
		res++;
		s++;
	}
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	if (!s || !(res = (char**)(malloc(sizeof(char*) * (wordcount(s, c) + 1)))))
		return (0);
	while (*s != '\0')
	{
		while ((*s == c) && (*s != '\0'))
			s++;
		if ((*s != c) && (*s != '\0'))
		{
			if (!(res[i] = (char*)(malloc(sizeof(char) * (wordlen(s, c) + 1)))))
				return (0);
			while ((*s != c) && (*s != '\0'))
				res[i][j++] = *s++;
			res[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	res[i] = NULL;
	return (res);
}
