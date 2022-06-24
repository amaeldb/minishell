/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:24:27 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/21 14:30:00 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_u(unsigned int par)
{
	return (to_base(par, "0123456789", 10));
}

int	conv_x(unsigned int par, char *base)
{
	return (to_base(par, base, 16));
}

int	conv_bigx(unsigned int par, char *base)
{
	return (to_base(par, base, 16));
}
