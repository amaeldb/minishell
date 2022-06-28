/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:06:34 by ade-beta          #+#    #+#             */
/*   Updated: 2022/06/28 14:19:47 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(int flag, char *str, int fd)
{
	write(fd, str, ft_strlen(str));
	if (flag)
		write(fd, "\n", 1);
	return (0);
}

int	ft_cd(char *str)
{
	char	*path;
	

	path = ft_strdup()
}