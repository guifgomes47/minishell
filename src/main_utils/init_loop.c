/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:48:37 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/28 23:07:03 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_clear	*clear_alloc(t_list **tenv, t_data *data)
{
	t_clear	*temp;

	temp = (t_clear *)ft_calloc(sizeof(t_clear), 1);
	if (!temp)
	{
		free(data);
		ft_lstclear(tenv);
		return (NULL);
	}
	temp->data = data;
	temp->tenv = tenv;
	temp->first = 0;
	return (temp);
}

t_data	*data_alloc(void)
{
	t_data	*tmp;

	tmp = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!tmp)
		return (NULL);
	tmp->free = -1;
	tmp->checker = -1;
	return (tmp);
}
