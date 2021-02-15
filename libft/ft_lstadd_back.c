/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:00:16 by aliens            #+#    #+#             */
/*   Updated: 2020/12/28 18:19:31 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst2;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst2 = ft_lstlast(*lst);
	lst2->next = new;
}
