/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:20:19 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/29 15:17:15 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*check_prompt(t_clear *clear)
{
	char	*line;

	if (!clear)
		return (NULL);
	line = prompt_shell();
	if (!line)
		return (NULL);
	return (line);
}

char	*choose_prompt(t_clear *clear)
{
	if (!clear->first)
	{
		ft_putstr_fd("Clear first not set.\n", 2);
	}
	clear->first++;
	if (clear->data->handler == 0)
		return (check_prompt(clear));
	return (check_prompt(clear));
}
