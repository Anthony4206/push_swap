/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_keep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:15:53 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/26 10:26:24 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_keep(t_list **a)
{
	t_list	*tmp;
	int		place;

	if (!*a)
		return ;
	tmp = *a;
	place = (*a)->place;
	(*a)->keep = 1;
	*a = (*a)->next;
	while (*a)
	{
		if ((*a)->place > place)
		{
			(*a)->keep = 1;
			place = (*a)->place;
		}
		else
			(*a)->keep = 0;
		*a = (*a)->next;
	}
	*a = tmp;
}
