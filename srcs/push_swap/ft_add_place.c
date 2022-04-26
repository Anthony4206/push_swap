/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 07:28:24 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/25 18:31:12 by Anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_chr_min(t_list **a, int place)
{	
	t_list	*start;
	int		min;

	start = *a;
	min = (*a)->value;
	ft_putnbr((*a)->value);
	ft_putchar('\n');
	while (*a)
	{
		if ((*a)->value < min)
			min = (*a)->value;
		*a = (*a)->next;
	}
	*a = start;
	while (*a)
	{
			if ((*a)->value == min)
				(*a)->place = place;
			*a = (*a)->next;
	}
	*a = start;
	return (min);
}

static int	ft_chr_next_min(t_list **a, int min, int place)
{
	t_list	*start;
	int		new_min;

	start = *a;
	while ((*a)->value <= min)
		*a = (*a)->next;
	new_min = (*a)->value;
	while (*a)
	{
		if ((*a)->value < new_min && (*a)->value > min)
			new_min = (*a)->value;
		*a = (*a)->next;
	}
	*a = start;
	while (*a)
	{
		if ((*a)->value == new_min)
			(*a)->place = place;
		*a = (*a)->next;
	}
	*a = start;
	return (new_min);
}

void	ft_add_place(t_list **a)
{
	int	place;
	int	min;
	int	len;

	place = 0;
	len = ft_lstsize(*a);
	min = ft_chr_min(&(*a), place);
	place++;
	while (place < len)
	{
		min = ft_chr_next_min(&(*a), min, place);
		place++;
	}
}
