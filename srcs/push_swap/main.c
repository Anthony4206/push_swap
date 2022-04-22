/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:33:55 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/22 15:42:23 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (0);
	stack.a = ft_parsing(argc, argv);
	stack.b = NULL;
	ft_putnbr(stack.a->nb);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->nb);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->next->nb);
	ft_putchar('\n');
	ft_swap_a(&stack.a);
	ft_putnbr(stack.a->nb);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->nb);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->next->nb);
	ft_putchar('\n');
	return (0);
}
