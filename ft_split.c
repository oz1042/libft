/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryozuno <ryozuno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:42:24 by ryozuno           #+#    #+#             */
/*   Updated: 2023/10/17 07:43:14 by ryozuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			i++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (i);
}

static char	*get_next_word(const char **s, char c)
{
	int		len;
	char	*target;

	while (*s != NULL && **s == c)
		(*s)++;
	target = ft_strchr(*s, c);
	if (target != NULL)
		len = target - *s;
	else
		len = ft_strlen(*s);
	return (ft_substr(*s, 0, len));
}

static void	free_words(char **words, int count)
{
	int	i;

	i = 0;
	while (words != NULL && i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**words;

	i = 0;
	count = count_words(s, c);
	words = (char **)ft_calloc(count + 1, sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < count)
	{
		words[i] = get_next_word(&s, c);
		if (words[i] == NULL)
		{
			free_words(words, i);
			return (NULL);
		}
		s = s + ft_strlen(words[i]);
		i++;
	}
	words[i] = NULL;
	return (words);
}
