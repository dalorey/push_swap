/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:55:56 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/05 19:08:45 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char const *s1, char const *set, const int i)
{
	size_t	j;
	int		res;

	j = 0;
	res = 0;
	while (j < ft_strlen(set))
	{
		if (s1[i] == set[j])
			res = 1;
		j++;
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	dst = NULL;
	while (i <= j)
	{
		if (ft_checkset(s1, set, i))
			i++;
		else
			break ;
	}
	while (j >= i)
	{
		if (ft_checkset(s1, set, j))
			j--;
		else
			break ;
	}
	dst = ft_substr(s1, (unsigned int)i, j - i + 1);
	return (dst);
}
