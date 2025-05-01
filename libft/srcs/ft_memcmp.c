/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:13:15 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/05 19:08:45 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s11 = (const unsigned char *) s1;
	const unsigned char	*s22 = (const unsigned char *) s2;
	size_t				i;

	if (n == 0)
		return (0);
	i = 0;
	while ((i < n) && (s11[i] == s22[i]))
	{
		i++;
	}
	if (i == n)
		return (0);
	return (s11[i] - s22[i]);
}
