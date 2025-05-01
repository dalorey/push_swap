/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:57:56 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/05 19:08:45 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const unsigned char	*b = (const unsigned char *)big;
	const unsigned char	*l = (const unsigned char *)little;
	size_t				i;
	size_t				j;

	if (*l == 0)
		return ((char *)b);
	i = 0;
	while ((b[i] != '\0') && (i < len))
	{
		j = 0;
		while ((b[i + j] == l[j]) && (i + j < len)
			&& (b[i + j] != '\0') && (l[j] != '\0'))
			j++;
		if (l[j] == '\0')
			return ((char *)&b[i]);
		i++;
	}
	return (NULL);
}
