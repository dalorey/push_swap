/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:13:04 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/05 19:08:45 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count++;
		num = -num;
	}
	if (num == 0)
		count++;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static char	*ft_alloc(int len)
{
	char	*s;

	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[0] = '0';
	return (s);
}

char	*ft_itoa(int num)
{
	char	*str_num;
	int		len;
	int		i;
	long	n;

	n = (long) num;
	len = ft_int_len(n);
	str_num = ft_alloc(len);
	if (!str_num)
		return (NULL);
	if (n < 0)
	{
		str_num[0] = '-';
		n = -n;
	}
	i = len - 1;
	while (n != 0)
	{
		str_num[i] = ((n % 10) + '0');
		n = n / 10;
		i--;
	}
	str_num[len] = '\0';
	return (str_num);
}
