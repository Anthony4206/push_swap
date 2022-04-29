/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:33:55 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/29 12:29:41 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_info	info;
	t_move	move;
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	if (argc < 2)
		return (0);
	stack.a = ft_parsing(argc, argv);
	stack.b = NULL;
	i = 0;
	info.size_a = ft_lstsize(stack.a);
	ft_add_place(&stack.a);
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
	ft_putendl("___________________________");
	ft_putendl("___________________________");
	ft_a_to_b(&stack, &info);
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
	ft_a_to_b_2(&stack, &info, &move);
	tmp = stack.a;
	tmp2 = stack.b;
	ft_putendl("___________________________");
	ft_putendl("___________________________");
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
	/*ft_b_to_a_2(&stack, &info, &move);
	ft_putendl("___________________________");
	ft_putendl("___________________________");
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
	}*/
	return (0);
}
