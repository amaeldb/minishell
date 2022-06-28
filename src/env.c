/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 09:57:55 by ade-beta          #+#    #+#             */
/*   Updated: 2022/06/28 14:20:59 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*set_env(char **envd)
{
	t_env	*env;
	t_env	*ph;
	t_env	*ret;
	int		i;
	int		j;

	i = -1;
	ph = NULL;
	while (envd[++i])
	{
		env = (t_env *)malloc(sizeof(t_env));
		if (ph)
			ph->next = env;
		else
			ret = env;
		j = -1;
		while (envd[i][++j] && envd[i][j] != '=')
			continue ;
		envd[i][j++] = '\0';
		env->name = ft_strdup(envd[i]);
		env->content = ft_strdup(&envd[i][j]);
		env->next = NULL;
		ph = env;
	}
	return (ret);
}

t_env	*del_env(t_env *env)
{
	t_env	*ph;

	while (env)
	{
		ph = env;
		free(env->name);
		free(env->content);
		env = env->next;
		free(ph);
	}
	return (NULL);
}

void	print_env(t_env *env)
{
	t_env	*ph;

	ph = env;
	while (ph)
	{
		printf("%s=%s\n", ph->name, ph->content);
		ph = ph->next;
	}
}

void	export_env(t_env *env)
{
	t_env	*ph;

	ph = env;
	while (ph)
	{
		printf("declare -x %s=\"%s\"\n", ph->name, ph->content);
		ph = ph->next;
	}
}

char	*env_handle(char **envd, int opt, char *str, char *cont)
{
	static t_env	*env;

	if (opt == 0)
		env = set_env(envd);
	else if (opt == 1)
		print_env(env);
	else if (opt == 2)
		export_env(env);
	else if (opt == 3)
		export_var(env, str, cont);
	else if (opt == 4)
		env = unset_var(env, str);
	else if (opt == 5)
		return (get_var(env, str));
	else if (opt == -1)
		env = del_env(env);
	return (NULL);
}
