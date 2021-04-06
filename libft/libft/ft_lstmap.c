/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@students.s19.be>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:52:43 by aliens            #+#    #+#             */
/*   Updated: 2021/03/19 13:46:55 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*dst;

	if (!lst || !f)
		return (NULL);
	dst = NULL;
	while (lst)
	{
		lst2 = ft_lstnew(f(lst->content));
		if (!lst2)
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
