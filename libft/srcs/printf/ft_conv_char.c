/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevasse <alevasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:51:29 by alevasse          #+#    #+#             */
/*   Updated: 2022/04/21 09:15:16 by alevasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conv_char(int c, t_opts opts)
{
	int	len;

	len = 1;
	while (opts.wdt > 1 && !opts.flags.minus)
	{
		ft_putchar(' ');
		opts.wdt--;
		len++;
	}
	ft_putchar(c);
	while (opts.wdt > 1 && opts.flags.minus)
	{
		ft_putchar(' ');
		opts.wdt--;
		len++;
	}
	return (len);
}
