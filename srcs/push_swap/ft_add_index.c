/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 07:06:21 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/25 07:26:11 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_index(t_list **a)
{
	t_list	*start;
	int		i;

	i = 0;
	start = *a;
	while (*a)
	{
		(*a)->index = i++;
		(*a) = (*a)->next;
	}
	*a = start;
}
