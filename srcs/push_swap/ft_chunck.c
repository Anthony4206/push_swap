#include "push_swap.h"

t_chunck	ft_chunck(t_list *a)
{
	t_chunck	ret;
	t_chunck	tmp;
	int			wdt;

	wdt = 0;
	tmp.start = 0;
	ret.start = 0;
	ret.end = 0;
	while (a->next)
	{
		if (a->value < a->next->value)
		{
			tmp.end - a->next->value;
			if (wdt < (tmp.end - tmp.start))
			{
				wdt = tmp.end - tmp.start;
				ret.start = tmp.start;
				ret.end = tmp.end;
			}
		}
		else
			tmp.start = a->next->index;
		a = a->next;
	}
	ret.len = ret.end - ret.start;
	return (ret);
}