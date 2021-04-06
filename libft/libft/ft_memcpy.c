/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:29:58 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 13:46:55 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptrsrc;
	char	*ptrdst;

	ptrdst = (char *)dst;
	ptrsrc = (char *)src;
	if (!dst && !src)
		return (dst);
	while (n--)
		ptrdst[n] = ptrsrc[n];
	return (dst);
}
