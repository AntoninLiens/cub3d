/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:32:14 by aliens            #+#    #+#             */
/*   Updated: 2020/12/28 18:26:10 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n2;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		n2 = -n;
		ft_putchar_fd('-', fd);
	}
	else
		n2 = n;
	if (n2 > 9)
	{
		ft_putnbr_fd(n2 / 10, fd);
	}
	ft_putchar_fd('0' + n2 % 10, fd);
}
