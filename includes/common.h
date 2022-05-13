/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:41:37 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/13 15:08:38 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"

typedef struct s_stack {
	t_list	*a;
	t_list	*b;
}			t_stack;

t_list	*ft_parsing(int argc, char **argv);
void	ft_swap_a(t_list **a, int print);
void	ft_push_a(t_list **a, t_list **b);
void	ft_rotate_a(t_list **a, int print);
void	ft_reverse_rotate_a(t_list **a, int print);
void	ft_swap_b(t_list **b, int print);
void	ft_push_b(t_list **b, t_list **a);
void	ft_rotate_b(t_list **b, int print);
void	ft_reverse_rotate_b(t_list **b, int print);
void	ft_swap_ab(t_list **a, t_list **b, int print);
void	ft_rotate_ab(t_list **a, t_list **b, int print);
void	ft_reverse_rotate_ab(t_list **a, t_list **b, int print);

#endif