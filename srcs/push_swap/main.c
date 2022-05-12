/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:33:55 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/12 14:47:32 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_info	info;

	if (argc < 2)
		return (0);
	stack.a = ft_parsing(argc, argv);
	stack.b = NULL;
	if (ft_lstsize(stack.a) == 3)
	{
		ft_mini_swap(&stack);
		return (EXIT_SUCCESS);
	}
	ft_add_place(&stack.a);
	ft_a_to_b(&stack, &info);
	ft_b_to_a(&stack, &info);
	return (EXIT_SUCCESS);
}
