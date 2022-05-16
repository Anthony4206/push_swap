/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:21:31 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/16 09:25:19 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	ft_select_pvt(t_list *lst, int size, int third)
{
	t_list	pivot;

	while (lst)
	{
		if (lst->place == ((size / 3) * third))
			pivot = *lst;
		lst = lst->next;
	}
	return (pivot);
}

int	ft_check_condition(int a_place, int last_a, int b_place)
{
	if (a_place > b_place
		&& (a_place < last_a
			|| b_place > last_a))
		return (1);
	else if (a_place < last_a
		&& b_place > last_a)
		return (1);
	return (0);
}

void	ft_mini_swap(t_stack *stack)
{
	while (ft_lstsize(stack->a) > 3)
		ft_push_b(&stack->b, &stack->a);
	if ((stack->a->value < stack->a->next->value)
		&& (stack->a->next->value < ft_lstlast(stack->a)->value))
		return ;
	else if ((ft_lstlast(stack->a)->value < stack->a->value)
		&& (stack->a->value < stack->a->next->value))
		ft_reverse_rotate_a(&stack->a, 1);
	else if ((stack->a->next->value < ft_lstlast(stack->a)->value)
		&& (ft_lstlast(stack->a)->value > stack->a->value))
		ft_swap_a(&(stack->a), 1);
	else if ((stack->a->next->value < ft_lstlast(stack->a)->value)
		&& (ft_lstlast(stack->a)->value < stack->a->value))
		ft_rotate_a(&(stack->a), 1);
	else if ((stack->a->value > stack->a->next->value)
		&& (stack->a->next->value > ft_lstlast(stack->a)->value))
	{
		ft_swap_a(&(stack->a), 1);
		ft_reverse_rotate_a(&(stack->a), 1);
	}
	else
	{
		ft_swap_a(&(stack->a), 1);
		ft_rotate_a(&(stack->a), 1);
	}
}

void	ft_a_to_b(t_stack *stack, t_info *info)
{
	info->size_a = ft_lstsize(stack->a);
	info->small_pvt = ft_select_pvt(stack->a, info->size_a, 1);
	info->tall_pvt = ft_select_pvt(stack->a, info->size_a, 2);
	while (info->size_a--)
	{	
		info->tmp = stack->a;
		if (info->tmp->place >= info->tall_pvt.place)
			ft_rotate_a(&(stack->a), 1);
		else
		{
			ft_push_b(&(stack->b), &(stack->a));
			if (info->tmp->place < info->small_pvt.place)
				ft_rotate_b(&(stack->b), 1);
		}
	}
	while (stack->a)
	{
		if (ft_lstsize(stack->a) == 3)
		{
			ft_mini_swap(stack);
			return ;
		}
		ft_push_b(&stack->b, &stack->a);
	}
}

void	ft_b_to_a(t_stack *stack, t_info *info)
{
	t_move	move;
	t_move	save;
	int		last_a;

	while (stack->b)
	{
		last_a = ft_lstlast(stack->a)->place;
		if (ft_check_condition(stack->a->place, last_a, stack->b->place))
			ft_push_a(&(stack->a), &(stack->b));
		else
		{
			ft_add_index(stack);
			ft_bzero(&save, sizeof(t_move));
			ft_def_move(*stack, info, &move, &save);
			ft_move(stack, save);
		}
	}
	info->size_a = ft_lstsize(stack->a);
	if (stack->a->place < info->size_a / 2)
		while (stack->a->place)
			ft_reverse_rotate_a(&stack->a, 1);
	else
		while (stack->a->place)
			ft_rotate_a(&stack->a, 1);
}
