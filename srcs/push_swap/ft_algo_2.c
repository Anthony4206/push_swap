/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:49:44 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/10 07:50:57 by Anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_add_info(t_stack *stack, t_info *info)
{
//	info->top_a = stack->a;
//	info->top_b = stack->b;
	info->last_a = ft_lstlast(stack->a);
	info->size_a = ft_lstsize(stack->a);
	info->size_b = ft_lstsize(stack->b);
}

void	ft_pb_or_ra(t_stack *stack, t_chunck chunck, int len)
{
	if (((stack->a->index < chunck.start) || (stack->a->index > chunck.end))
		&& (!len || (stack->a->place < len)))
		ft_push_b(&(stack->b), &(stack->a));
	else
		ft_rotate_a(&(stack->a), 1);
}

int	ft_check_condition(t_stack *stack)
{
	int	last_a;

	last_a = ft_lstlast(stack->a)->place;
	if (stack->a->place > stack->b->place
		&& (stack->a->place < last_a
			|| stack->b->place > last_a))
	{
		if (stack->b->place == 8)
			ft_printf("Coucou 8\n");
		return (1);
	}
	else if (stack->a->place < last_a
		&& stack->b->place > last_a)
	{
		if (stack->b->place == 8)
			ft_printf("Coucou 8\n");
		return (1);
	}
	return (0);
}

void	ft_move_ab(t_stack *stack, t_move *move)
{
	while (move->ra_count > 0 && move->rb_count > 0)
	{
		ft_rotate_ab(&stack->a, &stack->b);
		move->ra_count--;
		move->rb_count--;
	}
	while (move->ra_count > 0 && move->rb_count > 0)
	{
		ft_reverse_rotate_ab(&stack->a, &stack->b);
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
//	ft_printf("%d\n", info->size_a);
	if (stack->a->index <= info->size_a / 2)
		move->ra_count = stack->a->index;
	else
	{
//		if (stack->b->place == 10)
		move->rra_count = info->size_a - stack->a->index;
//		ft_printf("*************\n");
//		ft_printf("%d\n", move->rra_count);
	}
	if (stack->b->index <= info->size_b / 2)
		move->rb_count = stack->b->index;
	else
		move->rrb_count = info->size_b - stack->b->index;
	move->sum = move->ra_count + move->rra_count
		+ move->rb_count + move->rrb_count;
}

void	ft_define_move(t_stack stack, t_info *info, t_move *move, t_move *save)
{	
	int	last_a;

	info->top_a = stack.a;
	info->size_b = ft_lstsize(stack.b);
	info->size_a = ft_lstsize(stack.a);
	ft_bzero(save, sizeof(t_move));
	ft_bzero(move, sizeof(t_move));
	while (stack.b)
	{
		stack.a = info->top_a;
		last_a = ft_lstlast(stack.a)->value;
		while (stack.a)
		{
			if (stack.b->place == 8)
			{
				ft_printf("%d\n", stack.a->place);
				ft_printf("%d\n", stack.b->place);
				ft_printf("%d\n", last_a);
				ft_printf("***************\n");
			}
			if (ft_check_condition(&stack))
			{
				if (stack.b->place == 8)
					ft_printf("Coucou 8\n");
				ft_add_move(&stack, info, move);
				ft_save_move(*move, save);
//				break ;
			}
			last_a = stack.a->value;
			stack.a = stack.a->next;
		}
		stack.b = stack.b->next;
	}
}

void	ft_b_to_a(t_stack *stack, t_info *info)
{
	t_move	move;
	t_move	save;

	while (stack->b)
	{
//		ft_add_info(stack, info);
		if (ft_check_condition(stack))
			ft_push_a(&(stack->a), &(stack->b));
		else
		{
			ft_add_index(&stack->a);
			ft_add_index(&stack->b);
			ft_define_move(*stack, info, &move, &save);
//			ft_printf("%d\n", save.sum);
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