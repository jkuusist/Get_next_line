/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:25:57 by jkuusist          #+#    #+#             */
/*   Updated: 2019/10/30 13:53:33 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int i;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		i = -n;
		ft_putchar_fd('-', fd);
	}
	else
		i = n;
	if ((i / 10) > 0)
		ft_putnbr_fd((i / 10), fd);
	ft_putchar_fd(((i % 10) + 48), fd);
}
