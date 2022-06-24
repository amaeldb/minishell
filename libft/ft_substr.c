/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:13:46 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/01 17:05:07 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	slen;
	char			*ret;

	if (!s)
		return (NULL);
	i = -1;
	slen = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		ret = malloc(1);
	else if (slen > len)
		ret = malloc(sizeof(char) * len + 1);
	else
		ret = malloc(sizeof(char) * slen + 1);
	if (!ret)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (++i < len && s[i + (size_t)start])
			ret[i] = (char)s[i + start];
	}
	ret[i] = '\0';
	return (ret);
}
