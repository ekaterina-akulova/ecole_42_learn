/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaderric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:21:20 by gaderric          #+#    #+#             */
/*   Updated: 2021/10/14 20:32:58 by gaderric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		++i;
	return (i);
}

static int	count_words(char *str, char c)
{
	int	num_words;

	num_words = 0;
	while (*str == c && *str)
		++str;
	while (*str)
	{
		++num_words;
		while (*str != c && *str)
			++str;
		while (*str == c && *str)
			++str;
	}
	return (num_words);
}

static char	*word_dupe(char *str, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = ft_wordlen(str, c);
	word = (char *) malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

static void	fill_words(char **array, char *str, char c)
{
	int	word_index;

	word_index = 0;
	while (*str == c && *str)
		++str;
	while (*str != '\0')
	{
		array[word_index] = word_dupe(str, c);
		if (!array[word_index] && array[0])
		{
			while (word_index != -1)
			{
				free(array[word_index]);
				array[word_index] = NULL;
				--word_index;
			}
			return ;
		}
		++word_index;
		while (*str != c && *str)
			++str;
		while (*str == c && *str)
			++str;
	}
}

char	**ft_split(char const *s, char c)
{
	int		num_words;
	char	**array;

	if (!s)
		return (NULL);
	num_words = count_words((char *)s, c);
	array = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!array)
		return (NULL);
	array[num_words] = NULL;
	fill_words(array, (char *)s, c);
	return (array);
}
