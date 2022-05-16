/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:33:55 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/16 10:34:29 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_info	info;

	if (argc < 2)
		return (0);
	if (ft_lstsize(stack.a) == 1)
		return (EXIT_SUCCESS);
	stack.a = ft_parsing(argc, argv);
	stack.b = NULL;
	ft_push_swap(&stack, &info);
	if (stack.a)
		ft_lstclear(&stack.a);
	if (stack.b)
		ft_lstclear(&stack.b);
	return (EXIT_SUCCESS);
}
