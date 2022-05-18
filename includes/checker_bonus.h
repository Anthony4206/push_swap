/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Anthony <Anthony@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:31:44 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/16 19:04:13 by Anthony          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft.h"

typedef struct s_stack {
	t_list	*a;
	t_list	*b;
}			t_stack;

int		ft_checker(t_stack *stack);
void	ft_make_input(t_stack *stack);
char	**ft_take_input(void);
void	ft_move_input(t_stack *stack, char *move);
void	ft_is_error(t_list *lst);
void	ft_error(t_stack *stack);
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