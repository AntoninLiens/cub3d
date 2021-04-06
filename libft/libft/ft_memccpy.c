/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:13:42 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 13:46:55 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned const char	*ptrsrc;
	unsigned char		*ptrdst;

	if (!dst || !src)
		return (NULL);
	ptrsrc = (unsigned const char *)src;
	ptrdst = (unsigned char *)dst;
	i = -1;
	while (++i < n)
	{
		ptrdst[i] = ptrsrc[i];
		if (ptrsrc[i] == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
