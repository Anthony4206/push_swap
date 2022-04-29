/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:03:45 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/29 10:53:49 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunck_size(t_list *lst, int chunck)
{
	size_t	i;

	i = 0;
	while (lst->chunck == chunck)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
