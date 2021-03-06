/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:27:17 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 13:46:56 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long int	num2;
	unsigned long long int	num;
	int						i;
	int						sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num2 = num;
		num = num * 10 + (str[i] - '0');
		if (num >= LLONG_MAX || num < num2)
			return (ternarint(sign == 1, -1, 0));
		i++;
	}
	return (num * sign);
}
