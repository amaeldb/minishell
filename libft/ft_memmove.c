/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:43:52 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/01 17:06:20 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*strd;
	char	*strs;

	if (!dest && !src)
		return (NULL);
	i = -1;
	strd = (char *)dest;
	strs = (char *)src;
	if (dest > src)
	{
		while (n > 0)
		{
			strd[n - 1] = strs[n - 1];
			n--;
		}
	}
	else
	{
		while (++i < n)
			strd[i] = strs[i];
	}
	return ((void *)strd);
}
