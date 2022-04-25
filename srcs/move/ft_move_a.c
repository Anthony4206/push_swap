/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:36:32 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/23 16:11:25 by Anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **a)
{
	t_list	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

void	ft_push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = tmp->next;
	if (*b)
		tmp->next = *b;
	else
		tmp->next = NULL;
	*b = tmp;
}

void	ft_rotate_a(t_list **a)
{
	t_list	*tmp;
	t_list	*chr;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = tmp->next;
	chr = *a;
	while (chr->next)
		chr = chr->next;
	chr->next = tmp;
	tmp->next = NULL;
}

void	ft_reverse_rotate_a(t_list **a)
{
	t_list	*tmp;
	t_list	*chr;

	if (!*a || !(*a)->next)
		return ;
	chr = *a;
	while (chr->next)
	{
		tmp = chr;
		chr = chr->next;
	}
	chr->next = *a;
	*a = chr;
	tmp->next = NULL;
}
