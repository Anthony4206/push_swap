/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:52:44 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/18 13:42:47 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (0);
	stack.a = ft_add_parsing(argc, argv);
	stack.b = NULL;
	ft_make_input(&stack);
	if (ft_checker(&stack))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (stack.a)
		ft_lstclear(&stack.a);
	if (stack.b)
		ft_lstclear(&stack.b);
//	system("leaks checker");
	return (EXIT_SUCCESS);
}
