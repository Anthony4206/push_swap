/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:33:55 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/23 16:12:33 by Anthony          ###   ########.fr       */
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
	ft_putendl("Pile a :");
	ft_putnbr(stack.a->nb);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->nb);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->next->nb);
	ft_putchar('\n');
	ft_rotate_a(&stack.a);
	ft_putendl("Pile a :");
	ft_putnbr(stack.a->nb);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->nb);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->next->nb);
	ft_putchar('\n');
	ft_reverse_rotate_a(&stack.a);
	ft_putendl("Pile a :");
	ft_putnbr(stack.a->nb);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->nb);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->next->nb);
	ft_putchar('\n');
	return (0);
}
