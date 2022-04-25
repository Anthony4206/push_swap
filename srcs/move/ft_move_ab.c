/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:36:24 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/25 14:59:59 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_ab(t_list **a, t_list **b)
{
	ft_swap_a(&(*a));
	ft_swap_b(&(*b));
}

void	ft_rotate_ab(t_list **a, t_list **b)
{
	ft_rotate_a(&(*a));
	ft_rotate_b(&(*b));
}

void	ft_reverse_rotate_ab(t_list **a, t_list **b)
{
	ft_reverse_rotate_a(&(*a));
	ft_reverse_rotate_b(&(*b));
}
