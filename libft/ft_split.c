/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:01:17 by aliens            #+#    #+#             */
/*   Updated: 2020/12/28 18:26:23 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void		ft_protect_free(char **dst, size_t i)
{
	while (i--)
		free(dst[i]);
	free(dst);
}

char			**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	size;
	size_t	w_s;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_word_number(s, c);
	if (!(dst = (char **)ft_calloc(sizeof(char *), size + 1)))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*s && *s == c)
			s++;
		w_s = ft_word_size(s, c);
		if (!(dst[i] = ft_substr(s, 0, ft_word_size(s, c))))
		{
			ft_protect_free(dst, i);
			return (NULL);
		}
		s += ft_word_size(s, c);
	}
	return (dst);
}
