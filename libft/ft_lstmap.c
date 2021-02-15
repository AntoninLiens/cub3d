/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:52:43 by aliens            #+#    #+#             */
/*   Updated: 2020/12/28 18:20:22 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_protect_free(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*dst;

	if (!lst || !f)
		return (NULL);
	dst = NULL;
	while (lst)
	{
		if (!(lst2 = ft_lstnew(f(lst->content))))
		{
			if (!del)
				ft_protect_free(&lst2);
			else
				ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&dst, lst2);
		lst = lst->next;
	}
	return (dst);
}
