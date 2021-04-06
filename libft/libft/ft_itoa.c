/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:45:08 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 13:46:55 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_size(int n, int a)
{
	if (!n)
		return (a);
	else if (n < 0)
		return (ft_size(n / -10, a + 2));
	else
		return (ft_size(n / 10, a + 1));
}

char	*ft_itoa(int n)
{
	int				size;
	unsigned int	n2;
	char			*dst;

	size = ternarint(n, ft_size(n, 0), 1);
	n2 = ternarint(n < 0, -n, n);
	dst = (char *)ft_calloc(sizeof(char), size + 1);
	if (!dst)
		return (NULL);
	ft_memset(dst, '0', size);
	if (!n)
		return (dst);
	while (size)
	{
		dst[size - 1] = n2 % 10 + '0';
		if (!n2 && !size - 1)
			dst[size - 1] = '-';
		n2 /= 10;
		size--;
	}
	return (dst);
}
