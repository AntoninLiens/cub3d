/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:13:44 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 13:46:56 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
