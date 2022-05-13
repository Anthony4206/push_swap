/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:38:02 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/13 15:04:48 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

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
void	ft_is_error(t_list **lst);
void	ft_move(t_stack *stack, t_move move);
void	ft_def_move(t_stack stack, t_info *info, t_move *move, t_move *save);
void	ft_add_move(t_stack *stack, t_info *info, t_move *move);
int		ft_check_condition(int a_place, int last_a, int b_place);
void	ft_save_move(t_move move, t_move *save);

#endif