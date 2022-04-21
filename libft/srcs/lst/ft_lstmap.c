/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:05:34 by alevasse          #+#    #+#             */
/*   Updated: 2022/03/25 11:04:29 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_secure(void *content, void (*del)(void *))
{
	t_list	*secure;

	secure = ft_lstnew(content);
	if (!secure)
		del(content);
	return (secure);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*begin;

	if (!lst)
		return (NULL);
	begin = ft_secure((*f)(lst->content), del);
	if (!begin)
		return (NULL);
	lst = lst->next;
	new = begin;
	while (lst)
	{
		new->next = ft_secure((*f)(lst->content), del);
		if (!new->next)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}
