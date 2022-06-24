/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:34:43 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/21 14:35:47 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	to_base(long unsigned int i, char *base, unsigned int size);
int	conv_c(int par);
int	conv_s(char *par);
int	conv_p(long unsigned int par, char *base);
int	conv_d(int par);
int	conv_i(int par);
int	conv_u(unsigned int par);
int	conv_x(unsigned int par, char *base);
int	conv_bigx(unsigned int par, char *base);

#endif
