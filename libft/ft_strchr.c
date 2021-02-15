/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:12:37 by aliens            #+#    #+#             */
/*   Updated: 2020/12/28 18:26:47 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if (!c)
		return ((char *)s + ft_strlen(s));
	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return ((char *)s + i);
	return (0);
}
