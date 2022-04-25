/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:38:02 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/23 15:56:22 by Anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack {
	t_list	*a;
	t_list	*b;
}			t_stack;

t_list	*ft_parsing(int argc, char **argv);
void	ft_swap_a(t_list **a);
void	ft_push_a(t_list **a, t_list **b);
void	ft_rotate_a(t_list **a);
void	ft_reverse_rotate_a(t_list **a);
void	ft_swap_b(t_list **b);
void	ft_push_b(t_list **b, t_list **a);
void	ft_rotate_b(t_list **b);
void	ft_reverse_rotate_b(t_list **b);
void	ft_swap_ab(t_list **a, t_list **b);
void	ft_rotate_ab(t_list **a, t_list **b);
void	ft_reverse_rotate_ab(t_list **a, t_list **b);

#endif