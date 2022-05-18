#include "libft.h"

int	ft_free_tab(char **split, size_t len)
{
	size_t	i;

	i = 0;
	while (split[i] && i < len)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (-1);
}