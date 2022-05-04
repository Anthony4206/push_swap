/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:21:31 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/04 12:41:16 by alevasse         ###   ########.fr       */
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

t_move	ft_save_move(t_move *move)
{
	t_move	ret;

	ret.ra_count = move->ra_count;
	ret.rb_count = move->rb_count;
	ret.pa_count = move->pa_count;
	ret.pb_count = move->pb_count;
	return (ret);
}

void	ft_a_to_b(t_stack *stack, t_info *info)
{
	int		len;

	ft_add_place(&stack->a);
	len = ft_lstsize(stack->a);
	info->small_pvt = ft_select_pvt(stack->a, len, 1);
	info->tall_pvt = ft_select_pvt(stack->a, len, 2);
	while (len--)
	{	
		info->top_a = *stack->a;
		if (info->top_a.place >= info->tall_pvt.place)
			ft_rotate_a(&(stack->a), 1);
		else
		{
			ft_push_b(&(stack->b), &(stack->a));
			if (info->top_a.place < info->small_pvt.place)
				ft_rotate_b(&(stack->b), 1);
		}
	}
}

void	ft_a_to_b_3(t_stack *stack, t_info *info, t_move *move, int size)
{
	t_move		save;

	if (size < 3)
		return ;
	ft_add_place(&stack->a);
	ft_bzero(move, sizeof(t_move));
	info->small_pvt = ft_select_pvt(stack->a, size, 1);
	info->tall_pvt = ft_select_pvt(stack->a, size, 2);
	while (size--)
	{
		info->top_a = *stack->a;
		if (info->top_a.place >= info->tall_pvt.place)
		{
			ft_rotate_a(&(stack->a), 1);
			move->ra_count++;
		}
		else
		{
			ft_push_b(&(stack->b), &(stack->a));
			move->pb_count++;
			if (info->top_a.place >= info->small_pvt.place)
			{
				ft_rotate_b(&(stack->b), 1);
				move->rb_count++;
			}
		}
	}
	save = ft_save_move(move);
	while (save.ra_count-- && save.rb_count--)
		ft_reverse_rotate_ab(&(stack->a), &(stack->b));
	ft_a_to_b_3(stack, info, move, move->ra_count);
//	ft_printf("%d\n", move->rb_count);
	ft_b_to_a_3(stack, info, move, move->rb_count);
	ft_b_to_a_3(stack, info, move, (move->pb_count - move->rb_count));
}

void	ft_b_to_a_3(t_stack *stack, t_info *info, t_move *move, int size)
{
	t_move	save;

	ft_add_place(&stack->b);
	if (size < 3)
	{
		if (size == 2)
		{
			ft_push_a(&(stack->a), &(stack->b));
			ft_push_a(&(stack->a), &(stack->b));
		}
		else if (size == 1)
			ft_push_a(&(stack->a), &(stack->b));
		return ;
	}
	ft_bzero(move, sizeof(t_move));
	info->small_pvt = ft_select_pvt(stack->b, size, 1);
	info->tall_pvt = ft_select_pvt(stack->b, size, 2);
	while (size--)
	{	
		info->top_b = *stack->b;
		if (info->top_b.place < info->small_pvt.place)
		{
			ft_rotate_b(&(stack->b), 1);
			move->rb_count++;
		}
		else
		{
			ft_push_a(&(stack->a), &(stack->b));
			move->pa_count++;
			if (info->top_b.place < info->tall_pvt.place)
			{
				ft_rotate_a(&(stack->a), 1);
				move->ra_count++;
			}
		}
	}
	save = ft_save_move(move);
	ft_a_to_b_3(stack, info, move, (move->pa_count - move->ra_count));
	while (save.ra_count-- && save.rb_count--)
		ft_reverse_rotate_ab(&(stack->a), &(stack->b));
	ft_a_to_b_3(stack, info, move, move->ra_count);
	ft_b_to_a_3(stack, info, move, move->rb_count);
}
