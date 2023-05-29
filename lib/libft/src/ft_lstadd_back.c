/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:53:47 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/27 23:07:58 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstlast(t_list *list)
{
	t_list	*last;

	if (!list)
		return (list);
	while (list && list->next)
		list = list->next;
	last = list;
	return (last);
}

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*last;

	if (!*list)
	{
		*list = new;
		return ;
	}
	else
	{
		last = ft_lstlast(*list);
		last->next = new;
	}
}
