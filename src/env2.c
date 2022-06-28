/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:52:08 by ade-beta          #+#    #+#             */
/*   Updated: 2022/06/27 18:26:45 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*get_var(t_env *env, char *str)
{
	t_env	*ph;

	ph = env;
	while (ph)
	{
		if (!ft_strncmp(env->name, str, ft_strlen(env->name)))
			return (ph);
		ph = ph->next;
	}
	return (NULL);
}

void	export_var(t_env *env, char *str)
{
	t_env	*ph;

	ph = env;
	while (ph)
	{
		if (!ft_strncmp(env->name, str, ft_strlen(env->name)))
			printf("declare -x %s=\"%s\"\n", ph->name, ph->content);
		ph = ph->next;
	}
}

t_env	*unset_var(t_env *env, char *str)
{
	t_env	*ph;
	t_env	*prev;
	t_env	*ret;

	ph = env;
	ret = env;
	prev = NULL;
	while (ph)
	{
		if (!ft_strncmp(env->name, str, ft_strlen(env->name)))
		{
			free(ph->name);
			free(ph->content);
			if (prev)
				prev->next = ph->next;
			else
				ret = ph->next;
			free(ph);
			return (ret);
		}
		prev = ph;
		ph = ph->next;
	}
	return (env);
}

void	set_var(t_env *env, char *str, char *cont)
{
	t_env	*ph;
	t_env	*new;

	ph  = env;
	while (ph->next)
		ph = ph->next;
	new = malloc(sizeof(t_env));
	new->name = ft_strdup(str);
	new->content = ft_strdup(cont);
	ph->next = new;
}