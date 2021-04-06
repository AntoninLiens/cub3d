/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:47:14 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 13:46:55 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptrsrc;
	char	*ptrdst;

	if (!dst && !src)
		return (NULL);
	ptrsrc = (char *)src;
	ptrdst = (char *)dst;
	i = -1;
	if (ptrdst <= ptrsrc)
		while (++i < len)
			ptrdst[i] = ptrsrc[i];
	else
		while (len--)
			ptrdst[len] = ptrsrc[len];
	return (dst);
}
