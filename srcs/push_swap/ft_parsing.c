#include "push_swap.h"

t_list	ft_parsing(int argc, char **argv)
{
	t_list	*ret;
	int		i;
	int		j;

	ret = NULL;
	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
	}
	while (argv[i])
	{
		while ()
		ft_lstadd_back(&ret, ft_lstnew(ft_atoi(argv[i])));
	}
	return (*ret);
}