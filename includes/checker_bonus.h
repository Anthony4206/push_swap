/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 07:31:44 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/13 15:04:13 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "common.h"

int		ft_checker(t_stack *stack);
void	ft_make_input(t_stack *stack);
char	**ft_take_input(void);
void	ft_move_input(t_stack *stack, char *move);

#endif