/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:49:44 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/06 13:06:28 by alevasse         ###   ########.fr       */
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
	info->top_a = stack->a;
	info->top_b = stack->b;
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

int	ft_check_condition(t_stack *stack, t_info *info)
{
	if (stack->a->place > stack->b->place
		&& (stack->a->place < info->last_a->place
			|| stack->b->place > info->last_a->place))
	{
//		ft_printf("Coucou\n");
		return (1);
	}
	else if (stack->a->place < info->last_a->place
		&& stack->b->place > info->last_a->place)
	{
//		ft_printf("Coucou\n");
		return (1);
	}
	return (0);
}

void	ft_define_move(t_stack *stack, t_info *info, t_move *move)
{	
	t_list	*tmp_a;
	t_list	*tmp_b;

	info->top_a = stack->a;
	tmp_a = stack->a;
	tmp_b = stack->b;
	while (stack->b)
	{
		stack->a = info->top_a;
		info->last_a->value = ft_lstlast(stack->a)->value;
		while (stack->a)
		{
			if (ft_check_condition(stack, info))
			{
//				ft_bzero(&move, sizeof(t_move));
//				ft_printf("Coucou\n");
				ft_add_move(stack, info, move);
				break ;
			}
			info->last_a->value = stack->a->value;
			stack->a = stack->a->next;
		}
		stack->b = stack->b->next;
	}
	stack->a = tmp_a;
	stack->b = tmp_b;
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
//	t_list		*tmp;
//	t_list		*tmp2;

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
	while (move.rra_count > 0)
	{
		ft_reverse_rotate_b(&stack->b, 1);
		move.rrb_count--;
	}
/*	tmp = stack->a;
	tmp2 = stack->b;
	while (stack->a)
	{
		ft_printf("%11d", stack->a->value);
		ft_putstr(" | ");
		ft_printf("%-11d\n", stack->a->place);
		ft_putchar('\n');
		stack->a = stack->a->next;
	}
	ft_putendl("___________________________");
	while (stack->b)
	{
		ft_printf("%11d", stack->b->value);
		ft_putstr(" | ");
		ft_printf("%-11d\n", stack->b->place);
		ft_putchar('\n');
		stack->b = stack->b->next;
	}
	stack->a = tmp;
	stack->b = tmp2;*/
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

void	ft_b_to_a(t_stack *stack, t_info *info)
{
	t_move	move;
//	t_move	save;

	while (stack->b)
	{
		ft_add_info(stack, info);
		if (ft_check_condition(stack, info))
			ft_push_a(&(stack->a), &(stack->b));
		else
		{
			ft_add_index(&stack->a);
			ft_add_index(&stack->b);
			ft_bzero(&move, sizeof(t_move));
			ft_define_move(stack, info, &move);
//			ft_bzero(&save, sizeof(t_move));
//			ft_save_move(move, &save);
//			ft_printf("Coucou\n");
			ft_move(stack, move);
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
