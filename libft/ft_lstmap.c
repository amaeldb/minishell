/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beta <ade-beta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:47:17 by ade-beta          #+#    #+#             */
/*   Updated: 2022/06/14 13:22:45 by ade-beta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;

	if (!lst)
		return (NULL);
	ret = NULL;
	while (lst != NULL)
	{
		ft_lstadd_back(&ret, ft_lstnew((*f)(lst->content)));
		if (!ft_lstlast(ret) || !ret)
		{
			ft_lstclear(&ret, (*del));
			return (NULL);
		}
		lst = lst->next;
	}
	return (ret);
}
