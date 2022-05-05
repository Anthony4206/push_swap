/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:33:55 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/05 18:37:53 by Anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		stack;
	t_info		info;
	t_list	*tmp;
	t_list	*tmp2;

	if (argc < 2)
		return (0);
	stack.a = ft_parsing(argc, argv);
	stack.b = NULL;
	ft_add_place(&stack.a);
	ft_a_to_b(&stack, &info);
	ft_printf("*********\n");
	ft_b_to_a(&stack, &info);
	tmp = stack.a;
	tmp2 = stack.b;
	while (stack.a)
	{
		ft_printf("%11d", stack.a->value);
		ft_putstr(" | ");
		ft_printf("%-11d\n", stack.a->place);
		ft_putchar('\n');
		stack.a = stack.a->next;
	}
	ft_putendl("___________________________");
	while (stack.b)
	{
		ft_printf("%11d", stack.b->value);
		ft_putstr(" | ");
		ft_printf("%-11d\n", stack.b->place);
		ft_putchar('\n');
		stack.b = stack.b->next;
	}
	stack.a = tmp;
	stack.b = tmp2;
	return (0);
}
