/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:45:20 by jkuusist          #+#    #+#             */
/*   Updated: 2019/10/29 14:36:45 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char ch;

	ch = (char)c;
	while (*s != ch)
	{
		if (*s == '\0')
		{
			if (ch == '\0')
				return (char *)(s);
			else
				return (0);
		}
		s++;
	}
	return (char *)(s);
}
