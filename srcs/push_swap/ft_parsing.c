#include "push_swap.h"

static int	ft_is_error(t_list **lst)
{
	ft_lstclear(&(*lst));
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

t_list	*ft_parsing(int argc, char **argv)
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
		j = 0;
		if (argv[i][0] == '+' || argv[i][0] == '-')
				j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) || !argv[i][j])
				ft_is_error(&ret);
			j++;
		}
		ft_lstadd_back(&ret, ft_lstnew(ft_atoi(argv[i++])));
	}
	return (ret);
}
