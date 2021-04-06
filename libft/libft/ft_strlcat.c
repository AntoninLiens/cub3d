/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:53:30 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 13:46:55 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_size;

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
