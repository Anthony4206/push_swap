/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:33:55 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/26 11:28:33 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_list	*tmp;
	int		len;
	int		i;

	if (argc < 2)
		return (0);
	stack.a = ft_parsing(argc, argv);
	stack.b = NULL;
	tmp = stack.a;
	i = 0;
	len = ft_lstsize(stack.a);
	ft_add_index(&stack.a);
	ft_add_place(&stack.a);
	ft_add_keep(&stack.a);
	while (stack.a)
	{
		ft_putnbr(stack.a->value);
		ft_putstr(" | ");
		ft_putnbr(stack.a->place);
		ft_putstr(" | ");
		ft_putnbr(stack.a->keep);
		ft_putchar('\n');
		stack.a = stack.a->next;
	}
//	stack.a = tmp;
//	ft_putchar('\n');
//	ft_putchar('\n');
/*	while (i++ < len)
		ft_push_a(&stack.a, &stack.b);
	while (stack.b)
	{
		ft_putnbr(stack.b->value);
		ft_putstr(" | ");
		ft_putnbr(stack.b->place);
		ft_putstr(" | ");
		ft_putnbr(stack.b->keep);
		ft_putchar('\n');
		stack.b = stack.b->next;
	}*/
/*	ft_putendl("Pile a :");
	ft_putnbr(stack.a->place);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->place);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->next->place);
	ft_putchar('\n');
	ft_rotate_a(&stack.a);
	ft_putendl("Pile a :");
	ft_putnbr(stack.a->place);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->place);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->next->place);
	ft_putchar('\n');
	ft_reverse_rotate_a(&stack.a);
	ft_putendl("Pile a :");
	ft_putnbr(stack.a->place);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->place);
	ft_putchar('\n');
	ft_putnbr(stack.a->next->next->place);
	ft_putchar('\n');*/
	return (0);
}
