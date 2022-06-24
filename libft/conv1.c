/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:24:15 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/21 14:24:22 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_c(int par)
{
	char	c;

	c = (char)par;
	write(1, &c, 1);
	return (1);
}

int	conv_s(char *par)
{
	int	i;

	i = -1;
	if (!par)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (par[++i])
		write(1, &par[i], 1);
	return (i);
}

int	conv_p(long unsigned int par, char *base)
{
	int	count;

	count = 2;
	write(1, "0x", 2);
	count += to_base(par, base, 16);
	return (count);
}

int	conv_d(int par)
{
	int	count;

	count = 0;
	if (par == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (par < 0)
	{
		write(1, "-", 1);
		par *= -1;
		count++;
	}
	count += to_base((long unsigned int)par, "0123456789", 10);
	return (count);
}

int	conv_i(int par)
{
	return (conv_d(par));
}
