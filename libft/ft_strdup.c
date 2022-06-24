/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:29:46 by ade-beta          #+#    #+#             */
/*   Updated: 2021/11/23 17:31:12 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = 0;
	while (src[i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (0);
	i = 0;
	while (src[i])
	{
		str[i] = (char)src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
