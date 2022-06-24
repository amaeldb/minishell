/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:55:21 by ade-beta          #+#    #+#             */
/*   Updated: 2021/11/29 13:55:25 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkmal(char **str, int size)
{
	int	i;
	int	f;

	i = -1;
	f = 0;
	while (++i < size)
		if (!str[i])
			f = 1;
	i = -1;
	if (f)
	{
		while (++i < size)
			free(str[i]);
		free(str);
		return (1);
	}
	return (0);
}
