/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:34:34 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/01 16:48:12 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*str;

	i = -1;
	str = (char *)big;
	if (!ft_strlen(little))
		return (str);
	if (len >= ft_strlen(little))
	{
		while (++i < (len - ft_strlen(little) + 1) && str[i])
			if (str[i] == little[0])
				if (!ft_strncmp(&str[i], little, ft_strlen(little)))
					return (&str[i]);
	}
	return (NULL);
}
