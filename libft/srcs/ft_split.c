/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlorenzo <dlorenzo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:24:28 by dlorenzo          #+#    #+#             */
/*   Updated: 2025/01/05 19:36:48 by dlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *str, char c)
{
	size_t	i;
	size_t	num_words;
	size_t	in_word;

	if (!str)
		return (0);
	i = 0;
	num_words = 0;
	in_word = 0;
	while (str[i])
	{
		if ((str[i] != c) && (str[i] != '\0'))
			in_word = 1;
		if (((str[i] == c) || (str[i] == '\0')) && (in_word))
		{
			num_words++;
			in_word = 0;
		}
		i++;
	}
	if ((in_word) && str[i] == '\0')
		num_words++;
	return (num_words);
}

static size_t	ft_word_len(char const *str, char c, size_t index)
{
	size_t	len;

	if (!str || (index >= ft_strlen(str)))
		return (0);
	len = 0;
	while ((str[index] != '\0') && (str[index] != c))
	{
		len++;
		index++;
	}
	return (len);
}

static char	*ft_store_word(char const *str, size_t index, size_t len)
{
	char	*tmp;

	tmp = malloc(len + 1);
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	ft_strlcpy(tmp, str + index, len + 1);
	return (tmp);
}

static char	**ft_free_word_list(char **word_list, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(word_list[i]);
		i++;
	}
	free(word_list);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	size_t	word_len;
	char	**word_list;

	i = 0;
	j = 0;
	words = ft_count_words(str, c);
	word_list = (char **)malloc((words + 1) * sizeof(char *));
	if (!word_list)
		return (NULL);
	while (str[i] != '\0')
	{
		if (((i == 0) || (i > 0 && (str[i - 1] == c))) && (str[i] != c))
		{
			word_len = ft_word_len(str, c, i);
			word_list[j] = ft_store_word(str, i, word_len);
			if (!word_list[j++])
				return (ft_free_word_list(word_list, j));
		}
		i++;
	}
	word_list[j] = NULL;
	return (word_list);
}
