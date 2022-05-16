/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:43:25 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/16 11:18:31 by alevasse         ###   ########.fr       */
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
	cmp = ret->next;
	while (ret->next)
	{
		while (cmp)
		{
			if (ret->value == cmp->value)
				ft_is_error(&ret);
			cmp = cmp->next;
		}
		ret = ret->next;
		cmp = ret->next;
	}
	ret = tmp;
}

int	ft_check_order(t_list *a)
{
	int	size;

	size = 1;
	while (a->next)
	{
		if (a->value < a->next->value)
			size++;
		else
			return (size);
		a = a->next;
	}
	return (size);
}

t_list	*ft_parsing(int argc, char **argv)
{
	t_list		*ret;
	int			i;
	long int	nb;

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
		nb = ft_atol(argv[i]);
		if (nb > INT32_MAX || nb < INT32_MIN)
			ft_is_error(&ret);
		ft_lstadd_back(&ret, ft_lstnew((int)nb));
		i++;
	}
	if (i > 1)
		ft_check_double(ret);
	return (ret);
}
