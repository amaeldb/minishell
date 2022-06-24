/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:55:47 by ade-beta          #+#    #+#             */
/*   Updated: 2021/11/29 14:01:51 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ret_z(void)
{
	char	*ret;

	ret = malloc(sizeof(char) * 2);
	if (!ret)
		return (NULL);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char	*ret_alloc(int size, int n, int neg)
{
	int		i;
	char	*ret;

	ret = malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	i = size;
	if (neg)
		ret[0] = '-';
	while (n > 0)
	{
		ret[--size] = '0' + (n % 10);
		n /= 10;
	}
	ret[i] = '\0';
	return (ret);
}

char	*retmin(void)
{
	char	*ret;

	ret = malloc(12);
	if (!ret)
		return (NULL);
	ret[11] = '\0';
	ret[0] = '-';
	ret[1] = '2';
	ret[2] = '1';
	ret[3] = '4';
	ret[4] = '7';
	ret[5] = '4';
	ret[6] = '8';
	ret[7] = '3';
	ret[8] = '6';
	ret[9] = '4';
	ret[10] = '8';
	return (ret);
}

char	*ft_itoa(int n)
{
	int	temp;
	int	size;
	int	neg;

	neg = 0;
	size = 0;
	if (n == -2147483648)
		return (retmin());
	if (n < 0)
	{
		neg = 1;
		n *= -1;
		size++;
	}
	temp = n;
	if (n == 0)
		return (ret_z());
	while (temp > 0)
	{
		size++;
		temp /= 10;
	}
	return (ret_alloc(size, n, neg));
}
