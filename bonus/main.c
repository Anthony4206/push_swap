/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:52:44 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/11 10:06:56 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_stack stack;

	if (argc < 2)
		return (0);
	stack.a = ft_parsing(argc, argv);
	stack.b = NULL;
	return (0);
}
