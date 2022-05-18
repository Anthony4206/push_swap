/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 07:51:57 by alevasse          #+#    #+#             */
/*   Updated: 2022/05/18 07:53:35 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_tab(char **split, size_t len)
{
	size_t	i;

	(void)len;
	i = 0;
	while (split[i] && i < len)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (-1);
}
