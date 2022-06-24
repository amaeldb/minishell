/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:48:46 by ade-beta          #+#    #+#             */
/*   Updated: 2022/06/24 15:23:34 by ade-beta         ###   ########.fr       */
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
	char	**path;

	(void)argc;
	(void)argv;
	path = get_path(env);
	if (!path)
		return (0);
	printf("%s\n", path[0]);
	return (0);
}