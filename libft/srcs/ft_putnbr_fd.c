/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:04:14 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/05 19:08:45 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>	// For INT_MIN

void	ft_putnbr_fd(int num, int fd)
{
	char	numc;

	numc = ' ';
	if (num == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		if (num < 0)
		{
			ft_putchar_fd('-', fd);
			num = -num;
		}
		if (num > 9)
		{
			ft_putnbr_fd(num / 10, fd);
			num = num % 10;
		}
		numc = num + '0';
		ft_putchar_fd(numc, fd);
	}
}
