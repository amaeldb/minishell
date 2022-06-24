/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:43:23 by ade-beta          #+#    #+#             */
/*   Updated: 2021/12/01 16:58:43 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*nullret(void)
{
	char	*ret;

	ret = malloc (1);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	return (ret);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ret;
	int		cf;
	int		cb;
	int		i;

	i = -1;
	cf = 0;
	cb = 0;
	while (ft_strchr(set, (char)s1[++i]) != NULL && s1[i])
		cf++;
	if (cf == (int)ft_strlen(s1))
		return (nullret());
	i = 0;
	while (ft_strchr(set, (char)s1[ft_strlen(s1) - (++i)])
		!= NULL && (int)ft_strlen(s1) != i)
		cb++;
	ret = malloc(ft_strlen(s1) - (cf + cb) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < (int)(ft_strlen(s1) - (cf + cb)))
		ret[i] = (char)s1[i + cf];
	ret[i] = '\0';
	return (ret);
}
