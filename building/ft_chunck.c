/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 07:50:51 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/03 06:16:05 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunck	ft_chunck(t_list *a)
{
	t_chunck	ret;
	t_chunck	tmp;
	int			wdt;

	wdt = 0;
	tmp.start = 0;
	ret.start = 0;
	ret.end = 0;
	while (a->next)
	{
		if (a->value < a->next->value)
		{
			tmp.end = a->next->index;
			if (wdt < (tmp.end - tmp.start))
			{
				wdt = tmp.end - tmp.start;
				ret.start = tmp.start;
				ret.end = tmp.end;
			}
		}
		else
			tmp.start = a->next->index;
		a = a->next;
	}
	ret.len = ret.end - ret.start + 1;
	return (ret);
}
