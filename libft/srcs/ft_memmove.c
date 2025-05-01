/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:47:44 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/05 19:08:45 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s = (unsigned char *)src;
	unsigned char		*d;

	if ((!src && !dst))
		return (NULL);
	d = (unsigned char *)dst;
	if ((s > d) && (n != 0))
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if ((s < d) && (n != 0))
	{
		i = n;
		while (i--)
			d[i] = s[i];
	}
	return (d);
}
