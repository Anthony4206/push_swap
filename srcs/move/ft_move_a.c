/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:36:32 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/09 14:43:33 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **a, int print)
{
	t_list	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	if (print)
		ft_printf("sa\n");}

void	ft_push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = tmp->next;
	if (*a)
		tmp->next = *a;
	else
		tmp->next = NULL;
	*a = tmp;
	ft_printf("pa\n");
}

void	ft_rotate_a(t_list **a, int print)
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
	if (print)
		ft_printf("ra\n");
}

void	ft_reverse_rotate_a(t_list **a, int print)
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
	if (print)
		ft_printf("rra\n");
}
