/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:21:31 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/12 10:53:28 by alevasse         ###   ########.fr       */
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

void	ft_a_to_b(t_stack *stack, t_info *info)
{
	int		len;

	len = ft_lstsize(stack->a);
	info->small_pvt = ft_select_pvt(stack->a, len, 1);
	info->tall_pvt = ft_select_pvt(stack->a, len, 2);
	while (len--)
	{	
		info->top_a = stack->a;
		if (info->top_a->place >= info->tall_pvt.place)
			ft_rotate_a(&(stack->a), 1);
		else
		{
			ft_push_b(&(stack->b), &(stack->a));
			if (info->top_a->place < info->small_pvt.place)
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

	while (stack->b)
	{
		if (ft_check_condition(stack->a->place, ft_lstlast(stack->a)->place, stack->b->place))
			ft_push_a(&(stack->a), &(stack->b));
		else
		{
			ft_add_index(stack);
			ft_bzero(&save, sizeof(t_move));
			ft_define_move(*stack, info, &move, &save);
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
