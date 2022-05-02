#include "push_swap.h"

void	ft_mini_swap(t_stack *stack)
{
	while (ft_lstsize(stack->a) > 3)
		ft_push_b(&stack->b, &stack->a);
	if ((stack->a->value < stack->a->next->value)
		&& (stack->a->next->value < ft_lstlast(stack->a)->value))
		return ;
	else if ((ft_lstlast(stack->a)->value < stack->a->value) 
		&& (stack->a->value < stack->a->next->value))
		ft_reverse_rotate_a(&stack->a);
	else if ((stack->a->next->value < ft_lstlast(stack->a)->value)
		&& (ft_lstlast(stack->a)->value > stack->a->value))
		ft_swap_a(&(stack->a));
	else if ((stack->a->next->value < ft_lstlast(stack->a)->value)
		&& (ft_lstlast(stack->a)->value < stack->a->value))
		ft_rotate_a(&(stack->a));
	else if ((stack->a->value > stack->a->next->value)
		&& (stack->a->next->value > ft_lstlast(stack->a)->value))
	{
		ft_swap_a(&(stack->a));
		ft_reverse_rotate_a(&(stack->a));
	}
	else
	{
		ft_swap_a(&(stack->a));
		ft_rotate_a(&(stack->a));
	}
}

void	ft_a_to_b(t_stack *stack, t_chunck chunck, t_info *info)
{
	int	i;
	int 

	info->size_a = ft_lstsize(stack->a);

}
