/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ab_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:36:24 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/16 12:31:56 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
