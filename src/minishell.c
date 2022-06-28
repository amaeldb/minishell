/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:48:46 by ade-beta          #+#    #+#             */
/*   Updated: 2022/06/28 11:48:40 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	printf("%d\n", ft_strncmp("TESTY", "TEST", ft_strlen("TESTY") + 1));
	(void)env_handle(env, 0, NULL, NULL);
	(void)env_handle(NULL, 3, "TEST", "Hello World");
	(void)env_handle(NULL, 1, NULL, NULL);
	(void)env_handle(NULL, -1, NULL, NULL);
	return (0);
}
