/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:15:06 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/17 11:32:22 by Anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*clear;

	while (*lst)
	{
		clear = *lst;
		*lst = clear->next;
		free(clear);
	}
	*lst = NULL;
}
