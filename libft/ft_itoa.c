/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:43:58 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/05 13:36:59 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		numlen(int num)
{
	int len;

	len = 0;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char		*handle_edge_cases(char *s, int n)
{
	if ((n == 0) || (n == -0))
		ft_strcpy(s, "0");
	if (n == -2147483648)
		ft_strcpy(s, "-2147483648\0");
	return (s);
}

char			*ft_itoa(int n)
{
	int				i;
	char			*res;

	i = numlen(n);
	if (!(res = (char*)(malloc(sizeof(char) * (i + 1)))))
		return (0);
	if ((n == 0) || (n == -0) || (n == -2147483648))
	{
		handle_edge_cases(res, n);
		return (res);
	}
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	res[i--] = '\0';
	while (n > 0)
	{
		res[i--] = n % 10 + 48;
		n /= 10;
	}
	return (res);
}
