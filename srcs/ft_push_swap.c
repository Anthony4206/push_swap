/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:31:23 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/16 11:56:27 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_a_to_b(t_stack *stack)
{
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

void	ft_push_swap(t_stack *stack, t_info *info)
{
	if (ft_check_order(stack->a) == ft_lstsize(stack->a))
		return ;
	if (ft_lstsize(stack->a) == 2)
	{
		ft_swap_a(&stack->a, 1);
		return ;
	}		
	if (ft_lstsize(stack->a) == 3)
	{
		ft_mini_swap(stack);
		return ;
	}
	ft_add_place(&stack->a);
	if (ft_lstsize(stack->a) > 99)
		ft_a_to_b(stack, info);
	else
		ft_small_a_to_b(stack);
	ft_b_to_a(stack, info);
}
