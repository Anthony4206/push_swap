/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:21:31 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/03 13:37:15 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	ft_select_pvt(t_list **lst, int size, int third)
{
	t_list	*pivot;
	t_list	*tmp;

	tmp = *lst;
	while (*lst)
	{
		if ((*lst)->place == ((size / 3) * third))
			pivot = *lst;
		*lst = (*lst)->next;
	}
	*lst = tmp;
	return (*pivot);
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

/*void	ft_a_to_b_quicksort(t_stack *stack, t_info *info)
{
	t_list	pivot;
	int		i;

	pivot = ft_select_pivot(&stack->a, info->size_a);
	i = 0;
	while (i++ < (info->size_a))
	{
		info->top_a = *stack->a;
		if (info->top_a.place >= pivot.place)
			ft_rotate_a(&(stack->a));
		else
			ft_push_b(&(stack->b), &(stack->a));
	}
}

void	ft_a_to_b_quicksort_plus(t_stack *stack, t_info *info)
{
	t_list	pivot;
	int		i;
	int		ra_count;
	int		pb_count;

	pivot = ft_select_pivot(&stack->a, info->size_a);
	i = 0;
	ra_count = 0;
	pb_count = 0;
	while (i++ < (info->size_a))
	{
		info->top_a = *stack->a;
		if (info->top_a.place >= pivot.place)
		{
			ft_rotate_a(&(stack->a));
			ra_count++;
		}
		else
		{
			ft_push_b(&(stack->b), &(stack->a));
			pb_count++;
		}
	}
	while (ra_count--)
		ft_reverse_rotate_a(&(stack->a));
}*/

void	ft_a_to_b(t_stack *stack, t_info *info)
{
	int		len;

	len = ft_lstsize(stack->a);
	info->small_pvt = ft_select_pvt(&(stack->a), len, 1);
	info->tall_pvt = ft_select_pvt(&(stack->a), len, 2);
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

void	ft_a_to_b_2(t_stack *stack, t_info *info, t_move *move)
{
	int		len;

	ft_add_place(&stack->a);
	len = ft_lstsize(stack->a);
	ft_bzero(move, sizeof(t_move));
	info->small_pvt = ft_select_pvt(&(stack->a), len, 1);
	info->tall_pvt = ft_select_pvt(&(stack->a), len, 2);
	while (len--)
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
	while (move->ra_count-- && move->rb_count--)
		ft_reverse_rotate_ab(&(stack->a), &(stack->b));
}

void	ft_b_to_a_2(t_stack *stack, t_info *info, t_move *move)
{
	int		len;

	len = ft_lstsize(stack->b);
	ft_add_place(&stack->a);
	info->small_pvt = ft_select_pvt(&(stack->b), len, 1);
	info->tall_pvt = ft_select_pvt(&(stack->b), len, 2);
	while (len--)
	{
		info->top_b = *stack->b;
		if (info->top_b.place >= info->tall_pvt.place)
		{
			ft_rotate_b(&(stack->b), 1);
			move->ra_count++;
		}
		else
		{
			ft_push_a(&(stack->a), &(stack->b));
			move->pb_count++;
			if (info->top_b.place < info->small_pvt.place)
			{
				ft_rotate_a(&(stack->a), 1);
				move->rb_count++;
			}
		}
	}
	while (move->ra_count-- && move->rb_count--)
		ft_reverse_rotate_ab(&(stack->a), &(stack->b));
}

void	ft_a_to_b_3(t_stack *stack, t_info *info, t_move *move, int size)
{
	t_move		save;

	ft_add_place(&stack->a);
//	len = ft_lstsize(stack->a);
	if (size < 3)
		return ;
	if (size == 3)
		ft_mini_swap(stack);
	ft_bzero(move, sizeof(t_move));
	info->small_pvt = ft_select_pvt(&(stack->a), size, 1);
	info->tall_pvt = ft_select_pvt(&(stack->a), size, 2);
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
	while (move->ra_count-- && move->rb_count--)
		ft_reverse_rotate_ab(&(stack->a), &(stack->b));
	ft_a_to_b_3(stack, info, move, save.ra_count);
	ft_b_to_a_3(stack, info, move, save.rb_count);
	ft_b_to_a_3(stack, info, move, (save.pb_count - save.rb_count));
}

void	ft_b_to_a_3(t_stack *stack, t_info *info, t_move *move, int size)
{
	t_move	save;

//	ft_add_place(&stack->b);
	size = ft_lstsize(stack->a);
	if (size < 3)
		return ;
	if (size == 3)
		ft_mini_swap(stack);
	ft_bzero(move, sizeof(t_move));
	info->small_pvt = ft_select_pvt(&(stack->a), size, 1);
	info->tall_pvt = ft_select_pvt(&(stack->a), size, 2);
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
	ft_a_to_b_3(stack, info, move, (move->pa_count - move->ra_count));
	while (move->ra_count-- && move->rb_count--)
		ft_reverse_rotate_ab(&(stack->a), &(stack->b));
	ft_a_to_b_3(stack, info, move, move->ra_count);
	ft_b_to_a_3(stack, info, move, move->rb_count);
}
