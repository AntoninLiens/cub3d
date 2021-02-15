/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:17:05 by aliens            #+#    #+#             */
/*   Updated: 2020/12/28 18:20:29 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*dst;

	if (!(dst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	dst->content = content;
	dst->next = NULL;
	return (dst);
}
