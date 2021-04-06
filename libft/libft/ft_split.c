/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:01:17 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 13:46:55 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_word_size(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_word_number(char const *s, char c)
{
	size_t	w;
	size_t	i;

	w = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			w++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (w);
}

static char	**ft_protect_free(char **dst, size_t i)
{
	while (i--)
		free(dst[i]);
	free(dst);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	size;
	size_t	w_s;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_word_number(s, c);
	dst = (char **)ft_calloc(sizeof(char *), size + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*s && *s == c)
			s++;
		w_s = ft_word_size(s, c);
		dst[i] = ft_substr(s, 0, ft_word_size(s, c));
		if (!dst[i])
			return (ft_protect_free(dst, i));
		s += ft_word_size(s, c);
	}
	return (dst);
}
