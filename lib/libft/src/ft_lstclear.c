/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:29:27 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/28 13:15:23 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstdelone(t_list *list)
{
	if (!list)
		return ;
	free(list);
}

void	ft_lstclear(t_list **list)
{
	t_list	*temp;

	if (!list)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		if (*list)
			ft_lstdelone(*list);
		*list = temp;
	}
	free(list);
	list = NULL;
}
