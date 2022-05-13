/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:49:44 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/13 08:11:29 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_move_ab(t_stack *stack, t_move *move)
{
	while (move->ra_count > 0 && move->rb_count > 0)
	{
		ft_rotate_ab(&stack->a, &stack->b, 1);
		move->ra_count--;
		move->rb_count--;
	}
	while (move->rra_count > 0 && move->rrb_count > 0)
	{
		ft_reverse_rotate_ab(&stack->a, &stack->b, 1);
		move->rra_count--;
		move->rrb_count--;
	}
}

void	ft_move(t_stack *stack, t_move move)
{
	ft_move_ab(stack, &move);
	while (move.ra_count > 0)
	{
		ft_rotate_a(&stack->a, 1);
		move.ra_count--;
	}
	while (move.rb_count > 0)
	{
		ft_rotate_b(&stack->b, 1);
		move.rb_count--;
	}
	while (move.rra_count > 0)
	{
		ft_reverse_rotate_a(&stack->a, 1);
		move.rra_count--;
	}	
	while (move.rrb_count > 0)
	{
		ft_reverse_rotate_b(&stack->b, 1);
		move.rrb_count--;
	}
	ft_push_a(&(stack->a), &(stack->b));
}

void	ft_save_move(t_move move, t_move *save)
{
	if (!save->sum || move.sum < save->sum)
	{
		save->ra_count = move.ra_count;
		save->rra_count = move.rra_count;
		save->rb_count = move.rb_count;
		save->rrb_count = move.rrb_count;
		save->sum = move.sum;
	}
}

void	ft_add_move(t_stack *stack, t_info *info, t_move *move)
{
	if (stack->a->index <= info->size_a / 2)
		move->ra_count = stack->a->index;
	else
		move->rra_count = info->size_a - stack->a->index;
	if (stack->b->index <= info->size_b / 2)
		move->rb_count = stack->b->index;
	else
		move->rrb_count = info->size_b - stack->b->index;
	move->sum = move->ra_count + move->rra_count
		+ move->rb_count + move->rrb_count;
}

void	ft_def_move(t_stack stack, t_info *info, t_move *move, t_move *save)
{	
	int	last_a;

	info->tmp = stack.a;
	info->size_b = ft_lstsize(stack.b);
	info->size_a = ft_lstsize(stack.a);
	while (stack.b)
	{
		stack.a = info->tmp;
		last_a = ft_lstlast(stack.a)->place;
		while (stack.a)
		{
			if (ft_check_condition(stack.a->place, last_a, stack.b->place))
			{
				ft_bzero(move, sizeof(t_move));
				ft_add_move(&stack, info, move);
				ft_save_move(*move, save);
				break ;
			}
			last_a = stack.a->place;
			stack.a = stack.a->next;
		}
		stack.b = stack.b->next;
	}
}
