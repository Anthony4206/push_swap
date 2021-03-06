/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:31:23 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/18 13:47:30 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_error(t_stack *stack)
{
	if (stack->a)
		ft_lstclear(&stack->a);
	if (stack->b)
		ft_lstclear(&stack->b);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_move_input(t_stack *stack, char *move)
{
	if (!ft_strcmp(move, "sa"))
		ft_swap_a(&stack->a, 0);
	else if (!ft_strcmp(move, "sb"))
		ft_swap_b(&stack->b, 0);
	else if (!ft_strcmp(move, "ss"))
		ft_swap_ab(&stack->a, &stack->b, 0);
	else if (!ft_strcmp(move, "pa"))
		ft_push_a(&stack->a, 0);
	else if (!ft_strcmp(move, "pb"))
		ft_push_b(&stack->b, 0);
	else if (!ft_strcmp(move, "ra"))
		ft_rotate_a(&stack->a, 0);
	else if (!ft_strcmp(move, "rb"))
		ft_rotate_b(&stack->b, 0);
	else if (!ft_strcmp(move, "rr"))
		ft_rotate_ab(&stack->a, &stack->b, 0);
	else if (!ft_strcmp(move, "rra"))
		ft_reverse_rotate_a(&stack->a, 0);
	else if (!ft_strcmp(move, "rrb"))
		ft_reverse_rotate_b(&stack->b, 0);
	else if (!ft_strcmp(move, "rrr"))
		ft_reverse_rotate_ab(&stack->a, &stack->b, 0);
	else
		ft_error(stack);
}

char	**ft_take_input(void)
{
	char	*input;
	char	*tmp;
	char	**ret;

	tmp = NULL;
	input = get_next_line(0);
	while (input)
	{
		tmp = ft_strcat(tmp, input);
		free(input);
		input = get_next_line(0);
	}
	ret = ft_split(tmp, '\n');
	return (ret);
}

void	ft_make_input(t_stack *stack)
{
	int		i;
	char	**input;

	i = 0;
	input = ft_take_input();
	ft_printf("%s\n", input[i]);
	while (input[i])
	{
		ft_move_input(stack, input[i]);
		i++;
	}
}

int	ft_checker(t_stack *stack)
{
	if (stack->b)
		return (0);
	while (stack->a->next)
	{
		if (stack->a->value > stack->a->next->value)
			return (0);
		stack->a = stack->a->next;
	}
	return (1);
}
