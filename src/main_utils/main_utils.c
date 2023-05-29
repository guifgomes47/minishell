/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:06:28 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/28 12:58:41 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clean_lex(t_list *lex)
{
	t_list	*temp;

	if (!lex)
		return ;
	while (!lex)
	{
		temp = lex;
		lex = lex->next;
		free(temp);
	}
}

void	reset_ok(t_data *data)
{
	data->child = 1;
}
