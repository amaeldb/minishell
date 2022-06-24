/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:26:18 by ade-beta          #+#    #+#             */
/*   Updated: 2021/11/24 12:16:21 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
