#include "push_swap.h"

ft_rotate_both(t_stack *stack, t_move *move)

void	ft_move(t_stack *stack, t_move move)
{
	ft_rotate_both(stack, &move);
}

t_move	ft_move(t_list *a, t_list *b, t_info info)
{
	t_move	ret;
	t_list	*tmp;

	tmp = a;
	ft_bzero(&ret, sizeof(t_move));
	info->size_a = ft_lstsize(a);
	info->size_b = ft_lstsize(b);
	while (b)
	{
		a = tmp;
		last_a = ft_lstlast(a)->nb;
		while (a)
		{
			if (((stack->a->place > stack->b->place
					&& ((stack->a->place < ft_lstlast(stack->a)->place)
							|| stack->b->place > ft_lstlast(stack->a)->place)))
				|| ((stack->a->place < ft_lstlast(stack->a)->place)
					&& (stack->b->place > ft_lstlast(stack->a)->place)))
			{
				
			}
		}
		b = b->next;
	}
}
