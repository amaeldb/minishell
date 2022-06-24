/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:22:36 by ade-beta          #+#    #+#             */
/*   Updated: 2022/06/13 12:01:11 by ade-beta         ###   ########.fr       */
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

int	cspa(char *s, char c)
{
	int	count;
	int	prev;
	int	i;

	i = -1;
	prev = 0;
	count = 0;
	while (s[++i])
	{
		if ((s[i] == c && prev) || (!s[i + 1] && s[i] != c))
		{
			count++;
			prev = 0;
		}
		else if (s[i] != c)
			prev = 1;
	}
	return (count);
}

void	malsub(char **ret, char *s, char c)
{
	int	i;
	int	j;
	int	count;
	int	prev;

	i = -1;
	j = -1;
	prev = 0;
	count = 1;
	while (s[++i])
	{
		if (s[i] != c)
		{
			count++;
			prev = 1;
		}
		if ((s[i] == c && prev) || (s[i + 1] == '\0' && prev))
		{
			ret[++j] = malloc(sizeof(char) * count);
			prev = 0;
			count = 1;
		}
	}
}

void	set_char(char *str, char c, char **ret)
{
	int	i;
	int	j;
	int	k;
	int	is;

	is = 1;
	j = 0;
	i = -1;
	k = -1;
	while (str[++i])
	{
		if (str[i] != c)
		{
			ret[j][++k] = str[i];
			is = 0;
		}
		if ((str[i] == c && !is) || (str[i + 1] == '\0' && !is))
		{
			ret[j][++k] = '\0';
			j++;
			k = -1;
			is = 1;
		}
	}
}

char	**ft_split(const char *s, char c)
{
	int		count;
	char	**ret;

	if (!s)
		return (NULL);
	count = cspa((char *)s, c);
	ret = malloc(sizeof(char *) * (count + 1));
	if (!ret)
		return (NULL);
	ret[count] = NULL;
	malsub(ret, (char *)s, c);
	if (ft_checkmal(ret, count))
		return (NULL);
	set_char((char *)s, c, ret);
	return (ret);
}
