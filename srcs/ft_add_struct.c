/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 07:28:24 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/13 15:08:05 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_chr_min(t_list **a, int place)
{	
	t_list	*start;
	int		min;

	start = *a;
	min = (*a)->value;
	while (*a)
	{
		if ((*a)->value < min)
			min = (*a)->value;
		*a = (*a)->next;
	}
	*a = start;
	while (*a)
	{
		if ((*a)->value == min)
			(*a)->place = place;
		*a = (*a)->next;
	}
	*a = start;
	return (min);
}

static int	ft_chr_next_min(t_list **a, int min, int place)
{
	t_list	*start;
	int		new_min;

	start = *a;
	while ((*a)->value <= min)
		*a = (*a)->next;
	new_min = (*a)->value;
	while (*a)
	{
		if ((*a)->value < new_min && (*a)->value > min)
			new_min = (*a)->value;
		*a = (*a)->next;
	}
	*a = start;
	while (*a)
	{
		if ((*a)->value == new_min)
			(*a)->place = place;
		*a = (*a)->next;
	}
	*a = start;
	return (new_min);
}

void	ft_add_place(t_list **a)
{
	int	place;
	int	min;

	place = 0;
	min = ft_chr_min(&(*a), place);
	place++;
	while (place < ft_lstsize(*a))
	{
		min = ft_chr_next_min(&(*a), min, place);
		place++;
	}
}

void	ft_add_index(t_stack *stack)
{
	t_list	*start;
	int		i;

	i = 0;
	start = stack->a;
	while (stack->a)
	{
		stack->a->index = i++;
		stack->a = stack->a->next;
	}
	stack->a = start;
	i = 0;
	start = stack->b;
	while (stack->b)
	{
		stack->b->index = i++;
		stack->b = stack->b->next;
	}
	stack->b = start;
}
