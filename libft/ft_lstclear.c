/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:13:44 by aliens            #+#    #+#             */
/*   Updated: 2020/12/28 18:19:39 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst2;

	if (!lst)
		return ;
	while (*lst)
	{
		lst2 = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst2;
	}
}
