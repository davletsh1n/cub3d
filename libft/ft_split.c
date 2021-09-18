/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:24:40 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/06 11:14:02 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wordsctr(char const *s, char c)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			w++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (w);
}

static char		*wmaker(char *s, size_t len)
{
	char	*word;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static void		rleaks(char **m, int step)
{
	while (step--)
		free(m[step]);
	free(m);
}

static char		**filler(int words, char const *s, char c, char **m)
{
	int		begin;
	int		end;
	int		step;

	step = 0;
	end = 0;
	while (step < words)
	{
		while (s[end] == c)
			end++;
		begin = end;
		while (s[end] != c && s[end])
			end++;
		if (end > begin)
			m[step] = wmaker((char*)s + begin, end - begin);
		if (!m[step])
		{
			rleaks(m, step);
			return (NULL);
		}
		step++;
	}
	m[step] = NULL;
	return (m);
}

char			**ft_split(char const *s, char c)
{
	int		words;
	char	**m;

	if (s == NULL)
		return (NULL);
	words = wordsctr(s, c);
	m = malloc(sizeof(char*) * (words + 1));
	if (!m)
		return (NULL);
	filler(words, s, c, m);
	return (m);
}
