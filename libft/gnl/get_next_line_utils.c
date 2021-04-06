/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:56:06 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 13:47:42 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_save(const char *str)
{
	size_t	i;
	char	*dst;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			dst = ft_strdup(str + i + 1);
			free((void *)str);
			return (dst);
		}
	}
	free((void *)str);
	return (0);
}

char	*ft_line(char *str)
{
	size_t	s;
	char	*dst;

	s = 0;
	while (str[s] && str[s] != '\n')
		s++;
	dst = (char *)ft_calloc(sizeof(char), s + 1);
	if (!dst)
		return (NULL);
	while (s--)
		dst[s] = str[s];
	return (dst);
}

int	ft_end_line(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*dst;
	size_t	s;

	s = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)ft_calloc(sizeof(char), s);
	if (!dst)
	{
		if (s1)
			free((void *)s1);
		free((void *)s2);
		return (NULL);
	}
	ft_memcpy(dst, s1, ft_strlen(s1));
	ft_memcpy(dst + ft_strlen(s1), s2, ft_strlen(s2));
	free((void *)s1);
	return (dst);
}
