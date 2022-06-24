/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:03:42 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/21 14:30:26 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = -1;
	ret = (char *)s;
	while (ret[++i])
		if (ret[i] == (char)c)
			return (&ret[i]);
	if (!c)
		return (&ret[i]);
	return (NULL);
}

int	to_base(long unsigned int i, char *base, unsigned int size)
{
	int	count;

	count = 1;
	if (i % size != i)
		count += to_base(i / size, base, size);
	write(1, &base[i % size], 1);
	return (count);
}

int	conv(const char c, va_list *par)
{
	if (c == 'c')
		return (conv_c(va_arg(*par, int)));
	else if (c == 's')
		return (conv_s(va_arg(*par, char *)));
	else if (c == 'p')
		return (conv_p(va_arg(*par, long unsigned int), "0123456789abcdef"));
	else if (c == 'd')
		return (conv_d(va_arg(*par, int)));
	else if (c == 'i')
		return (conv_i(va_arg(*par, int)));
	else if (c == 'u')
		return (conv_u(va_arg(*par, unsigned int)));
	else if (c == 'x')
		return (conv_x(va_arg(*par, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (conv_bigx(va_arg(*par, unsigned int), "0123456789ABCDEF"));
	write(1, "%", 1);
	return (1);
}

int	reduc(char str, va_list *par)
{
	int	count;

	count = 0;
	if (ft_strchr("cspdiuxX%", str))
		count += conv(str, par);
	else
		count += conv_c((int)str);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	*par;
	int		i;
	int		count;

	if (!str)
		return (0);
	i = -1;
	count = 0;
	par = (va_list *)malloc(sizeof(va_list));
	va_start(*par, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
			count += reduc(str[++i], par);
		else
		{
			write(1, &str[i], 1);
			count++;
		}
	}
	va_end(*par);
	free(par);
	return (count);
}
