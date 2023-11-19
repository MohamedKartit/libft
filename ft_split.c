/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkartit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:04:39 by mkartit           #+#    #+#             */
/*   Updated: 2023/11/16 17:59:41 by mkartit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_cwords(const char *s, char c)
{
	unsigned int	count;
	int				n_word;

	n_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!n_word)
			{
				count++;
				n_word = 1;
			}
		}
		else
			n_word = 0;
		s++;
	}
	return (count);
}

static unsigned int	lwords(char const *str, char c)
{
	unsigned int	l;

	l = 0;
	while (*str && *str != c)
	{
		l++;
		str++;
	}
	return (l);
}

static void	free_strings(char **strings, int l)
{
	int	i;

	i = -1;
	while (++i <= l)
		free(strings[i]);
	free(strings);
}

char	**ft_coping(char **strings, char const *s, unsigned int n_words, char c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < n_words)
	{
		while (*s == c)
			s++;
		strings[i] = (char *)malloc(sizeof(char) * lwords(s, c) + 1);
		if (!strings[i])
		{
			free_strings(strings, i);
			return (NULL);
		}
		j = 0;
		while (*s && *s != c)
			strings[i][j++] = *s++;
		strings[i++][j] = '\0';
	}
	strings[i] = NULL;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	unsigned int	n_words;

	if (!s)
		return (NULL);
	n_words = ft_cwords(s, c);
	strings = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!strings)
		return (NULL);
	return (ft_coping(strings, s, n_words, c));
}
