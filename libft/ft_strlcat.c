/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:53:30 by aliens            #+#    #+#             */
/*   Updated: 2020/12/28 18:27:37 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t dst_size;

	if (!dst || !src)
		return (0);
	dst_size = ft_strlen(dst);
	if (dstsize <= dst_size)
		return (ft_strlen(src) + dstsize);
	i = -1;
	while (src[++i] && i < dstsize - dst_size - 1)
		dst[dst_size + i] = src[i];
	dst[dst_size + i] = 0;
	return (dst_size + ft_strlen(src));
}
