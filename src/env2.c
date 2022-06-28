/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:52:08 by ade-beta          #+#    #+#             */
/*   Updated: 2022/06/28 14:27:20 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var(t_env *env, char *str)
{
	t_env	*ph;

	ph = env;
	printf("test\n");
	while (ph)
	{
		if (!ft_strncmp(ph->name, str, ft_strlen(ph->name) + 1))
			return (ph->content);
		ph = ph->next;
	}
	return (NULL);
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
		if (!ft_strncmp(ph->name, str, ft_strlen(ph->name) + 1))
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

void	export_var(t_env *env, char *str, char *cont)
{
	t_env	*ph;
	t_env	*new;

	ph = env;
	while (ph->next && ft_strncmp(ph->name, str, ft_strlen(str) + 1))
		ph = ph->next;
	if (!ft_strncmp(ph->name, str, ft_strlen(str) + 1))
	{
		free(ph->content);
		ph->content = ft_strdup(cont);
		return ;
	}
	new = malloc(sizeof(t_env));
	new->name = ft_strdup(str);
	new->content = ft_strdup(cont);
	ph->next = new;
}
