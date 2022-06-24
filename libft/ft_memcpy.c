/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:43:25 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/01 16:34:55 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*strd;
	char	*strs;

	if (!dest && !src)
		return (NULL);
	i = 0;
	strd = (char *)dest;
	strs = (char *)src;
	while (i < n && strs[i])
	{
		strd[i] = strs[i];
		i++;
	}
	return (dest);
}
