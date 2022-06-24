/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:56:13 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/01 17:00:12 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		i;

	if (!s || !f)
		return (NULL);
	i = -1;
	ret = malloc(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	while (s[++i])
		ret[i] = (*f)(i, (char)s[i]);
	ret[i] = '\0';
	return (ret);
}
