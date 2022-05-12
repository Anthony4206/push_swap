/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:43:25 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/12 10:34:13 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_is_error(t_list **lst)
{
	ft_lstclear(&(*lst));
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	ft_check_digit(char *argv, t_list *ret)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '+' || argv[i] == '-')
				i++;
		while (argv[i])
		{
			if (!ft_isdigit(argv[i]) || !argv[i])
				ft_is_error(&ret);
			i++;
		}
	}
}

static void	ft_check_double(t_list *ret)
{
	t_list	*tmp;
	t_list	*cmp;

	tmp = ret;
	cmp = ret;
	while (ret->next->next)
	{
		while (cmp->next)
		{
			cmp = cmp->next;
			if (ret->value == cmp->value)
				ft_is_error(&ret);
		}
		ret = ret->next;
		cmp = ret;
	}
	ret = tmp;
}

t_list	*ft_parsing(int argc, char **argv)
{
	t_list	*ret;
	int		i;

	ret = NULL;
	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	while (argv[i])
	{
		ft_check_digit(argv[i], ret);
		ft_lstadd_back(&ret, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	if (i > 1)
		ft_check_double(ret);
	return (ret);
}
