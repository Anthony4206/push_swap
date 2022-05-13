/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:36:24 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/12 08:11:55 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_ab(t_list **a, t_list **b, int print)
{
	ft_swap_a(&(*a), 0);
	ft_swap_b(&(*b), 0);
	if (print)
		ft_printf("ss\n");
}

void	ft_rotate_ab(t_list **a, t_list **b, int print)
{
	ft_rotate_a(&(*a), 0);
	ft_rotate_b(&(*b), 0);
	if (print)
		ft_printf("rr\n");
}

void	ft_reverse_rotate_ab(t_list **a, t_list **b, int print)
{
	ft_reverse_rotate_a(&(*a), 0);
	ft_reverse_rotate_b(&(*b), 0);
	if (print)
		ft_printf("rrr\n");
}
