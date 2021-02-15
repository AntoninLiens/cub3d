/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:25:06 by aliens            #+#    #+#             */
/*   Updated: 2020/12/28 18:29:28 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	len > ft_strlen(s) - start + 1 ? len = ft_strlen(s) - start : len;
	if (ft_strlen(s) < start)
	{
		if (!(dst = (char *)ft_calloc(sizeof(char), 1)))
			return (NULL);
		return (dst);
	}
	if (!(dst = ft_calloc(sizeof(char), len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		dst[i] = s[start + i];
	return (dst);
}
