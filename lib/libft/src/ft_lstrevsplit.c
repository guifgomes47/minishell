/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrevsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:24:16 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/29 15:17:04 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstrevsplit(char **str)
{
	t_list	*list;
	t_list	*elem;
	int		i;

	list = NULL;
	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		elem = ft_lstnew(str[i]);
		if (!elem)
		{
			ft_lstclear(&list);
			return (NULL);
		}
		ft_lstadd_back(&list, elem);
	}
	return (list);
}
