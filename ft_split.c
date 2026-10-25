/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: thdeglos <thdeglos@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 12:32:34 by thdeglos         #+#    #+#              */
/*   Updated: 2026/10/19 12:32:34 by thdeglos        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
			count++;
		in_word = (*s != c);
		s++;
	}
	return (count);
}

static char	**free_words(char **words, size_t count)
{
	while (count--)
		free(words[count]);
	free(words);
	return (NULL);
}

static char	**fill_words(char **words, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			words[j] = ft_substr(s, start, i - start);
			if (!words[j])
				return (free_words(words, j));
			j++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!words)
		return (NULL);
	return (fill_words(words, s, c));
}
