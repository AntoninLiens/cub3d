/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:00:31 by aliens            #+#    #+#             */
/*   Updated: 2020/12/28 18:31:27 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;
	unsigned char	c2;

	if (!s)
		return (NULL);
	c2 = (unsigned char)c;
	s2 = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (*(s2 + i) == c2)
			return ((void *)(s + i));
	return (NULL);
}
