/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:45:07 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/05 19:08:00 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	const unsigned char	*n = (const unsigned char *)nptr;
	int					num;
	int					sign;

	num = 0;
	sign = 1;
	if (*n)
	{
		while (*n == ' ' || ((*n >= 9) && (*n <= 13)))
		{
			n++;
		}
		if (*n == '-')
			sign = -sign;
		if ((*n == '+') || (*n == '-'))
			n++;
		while (*n >= '0' && *n <= '9')
		{
			num = num * 10 + *n - '0';
			n++;
		}
		return (num * sign);
	}
	return (0);
}
