/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:38:28 by ade-beta          #+#    #+#             */
/*   Updated: 2022/06/28 12:57:27 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	int_hand(int sig)
{
	printf("SIGINT %d\n", sig);
	env_handle(NULL, -1, NULL, NULL);
	exit (0);
}

void	set_sig(void)
{
	signal(SIGINT, int_hand);
}
