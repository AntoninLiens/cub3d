/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:43:42 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 13:46:55 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	s;

	if (!s1 || !s2)
		return (NULL);
	s = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)ft_calloc(sizeof(char), s);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s1, ft_strlen(s1));
	ft_memcpy(dst + ft_strlen(s1), s2, ft_strlen(s2));
	return (dst);
}
