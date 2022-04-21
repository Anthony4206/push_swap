/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:15:06 by alevasse          #+#    #+#             */
/*   Updated: 2022/03/24 10:00:42 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clear;

	while (*lst)
	{
		del((*lst)->content);
		clear = *lst;
		*lst = clear->next;
		free(clear);
	}
	*lst = NULL;
}
