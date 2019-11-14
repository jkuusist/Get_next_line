/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:11:57 by jkuusist          #+#    #+#             */
/*   Updated: 2019/11/01 11:18:08 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_whitespace(char c)
{
	if ((c == ' ') || (c == '\t'))
		return (1);
	if ((c == '\n') || (c == '\v') || (c == '\f') || (c == '\r'))
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int					i;
	unsigned long long	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
	}
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (((str[i] >= '0') && (str[i] <= '9')))
	{
		res = res * 10 + ((unsigned long long)(str[i] - '0'));
		i++;
	}
	if (res > 9223372036854775807)
		return ((sign == -1) ? 0 : -1);
	return (res * sign);
}
