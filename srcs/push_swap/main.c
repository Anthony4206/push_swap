/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:33:55 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/02 15:23:50 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		stack;
	t_info		info;
	t_chunck	chunck;
	t_list	*tmp;
	t_list	*tmp2;

	if (argc < 2)
		return (0);
	stack.a = ft_parsing(argc, argv);
	stack.b = NULL;
	ft_add_index(&stack.a);
	ft_add_place(&stack.a);
	tmp = stack.a;
	tmp2 = stack.b;
	while (stack.a)
	{
		ft_printf("%11d", stack.a->index);
		ft_putstr(" | ");
		ft_printf("%-11d\n", stack.a->place);
		ft_putchar('\n');
		stack.a = stack.a->next;
	}
	ft_putendl("___________________________");
	while (stack.b)
	{
		ft_printf("%11d", stack.b->index);
		ft_putstr(" | ");
		ft_printf("%-11d\n", stack.b->place);
		ft_putchar('\n');
		stack.b = stack.b->next;
	}
	stack.a = tmp;
	stack.b = tmp2;
	chunck = ft_chunck(stack.a);
	if (chunck.len == ft_lstsize(stack.a))
		return (0);
	else if (chunck.len < 3)
		ft_mini_swap(&stack);
	else
		ft_a_to_b(&stack, chunck, &info);
	return (0);
}
