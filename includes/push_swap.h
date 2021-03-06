/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:38:02 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/18 07:14:22 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack {
	t_list	*a;
	t_list	*b;
}			t_stack;

typedef struct s_info {
	int		size_a;
	int		size_b;
	t_list	*last_a;
	t_list	*tmp;
	t_list	small_pvt;
	t_list	tall_pvt;
}			t_info;

typedef struct s_move {
	int	ra_count;
	int	rra_count;
	int	rb_count;
	int	rrb_count;
	int	sum;
}		t_move;

t_list	ft_select_pvt(t_list *lst, int size, int third);
void	ft_mini_swap(t_stack *stack);
void	ft_a_to_b(t_stack *stack, t_info *info);
void	ft_b_to_a(t_stack *stack, t_info *info);
void	ft_add_index(t_stack *stack);
void	ft_add_place(t_list **a);
void	ft_is_error(t_list *lst);
void	ft_move(t_stack *stack, t_move move);
void	ft_def_move(t_stack stack, t_info *info, t_move *move, t_move *save);
void	ft_add_move(t_stack *stack, t_info *info, t_move *move);
int		ft_check_condition(int a_place, int last_a, int b_place);
void	ft_save_move(t_move move, t_move *save);
int		ft_check_order(t_list *a);
void	ft_push_swap(t_stack *stack, t_info *info);
void	ft_small_a_to_b(t_stack *stack);
void	ft_free_split(int argc, char **argv, int i);

t_list	*ft_parsing(char **argv, t_list *ret, int *i);
t_list	*ft_add_parsing(int argc, char **argv);
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