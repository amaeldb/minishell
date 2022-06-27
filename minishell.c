/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:48:46 by ade-beta          #+#    #+#             */
/*   Updated: 2022/06/27 10:39:28 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path(char **env)
{
	int		i;
	char	**path;
	char	*del;

	i = -1;
	while (env[++i])
		if (ft_strnstr(env[i], "PATH", 4))
			del = ft_strdup(env[i]);
	path = ft_split(del, ':');
	free(del);
	return (path);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env_handle(env, 0, NULL);
	(void)env_handle(NULL, 1, NULL);
	(void)env_handle(NULL, -1, NULL);
	return (0);
}