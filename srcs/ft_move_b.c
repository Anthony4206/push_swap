/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:36:36 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/02 14:45:31 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_b(t_list **b, int print)
{
	t_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	if (print)
		ft_printf("sb\n");
}

void	ft_push_b(t_list **b, t_list **a)
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
	ft_printf("pb\n");
}

void	ft_rotate_b(t_list **b, int print)
{
	t_list	*tmp;
	t_list	*chr;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = tmp->next;
	chr = *b;
	while (chr->next)
		chr = chr->next;
	chr->next = tmp;
	tmp->next = NULL;
	if (print)
		ft_printf("rb\n");
}

void	ft_reverse_rotate_b(t_list **b, int print)
{
	t_list	*tmp;
	t_list	*chr;

	if (!*b || !(*b)->next)
		return ;
	chr = *b;
	while (chr->next)
	{
		tmp = chr;
		chr = chr->next;
	}
	chr->next = *b;
	*b = chr;
	tmp->next = NULL;
	if (print)
		ft_printf("rrb\n");
}
