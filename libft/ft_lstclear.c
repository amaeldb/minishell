/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:46:23 by ade-beta          #+#    #+#             */
/*   Updated: 2022/06/14 13:23:10 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;

	if (lst)
	{
		while (*lst != NULL)
		{
			nxt = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = nxt;
		}
	}
	*lst = NULL;
}
