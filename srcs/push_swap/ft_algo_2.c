/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:49:44 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/05 06:39:58 by Anthony          ###   ########.fr       */
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

void	ft_pb_or_ra(t_stack *stack, t_chunck chunck, int len)
{
	if (((stack->a->index < chunck.start) || (stack->a->index > chunck.end))
		&& (!len || (stack->a->place < len)))
		ft_push_b(&(stack->b), &(stack->a));
	else
		ft_rotate_a(&(stack->a), 1);
}

/*void	ft_a_to_b(t_stack *stack, t_chunck chunck, t_info *info)
{
	int	i;
	int	len_chunck;

	info->size_a = ft_lstsize(stack->a);
	if (info->size_a > 99)
	{
		i = 1;
		while (i < 3)
		{
			len_chunck = info->size_a * i / 3;
			while (ft_lstsize(stack->b) < len_chunck - chunck.len)
				ft_pb_or_ra(stack, chunck, len_chunck);
			i++;
		}
	}
	while (ft_lstsize(stack->a) > chunck.len)
		ft_pb_or_ra(stack, chunck, 0);
}*/

void	ft_b_to_a(t_stack *stack)
{
	if (((stack->a->place > stack->b->place
				&& ((stack->a->place < ft_lstlast(stack->a)->place)
						|| stack->b->place > ft_lstlast(stack->a)->place)))
		|| ((stack->a->place < ft_lstlast(stack->a)->place)
			&& (stack->b->place > ft_lstlast(stack->a)->place)))
		ft_push_a(&(stack->a), &(stack->b));
	else
	{
		ft_add_index(&stack->a);
		ft_add_index(&stack->b);

	}
}*/
