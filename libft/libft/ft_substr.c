/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:25:06 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 13:46:55 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	len = ternarint(len > ft_strlen(s) - start + 1, ft_strlen(s) - start, len);
	if (ft_strlen(s) < start)
	{
		dst = (char *)ft_calloc(sizeof(char), 1);
		if (!dst)
			return (NULL);
		return (dst);
	}
	dst = ft_calloc(sizeof(char), len + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (++i < len)
		dst[i] = s[start + i];
	return (dst);
}
