/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:26:15 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/28 20:40:28 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*prompt_shell(void)
{
	char	*line;
	char	*ptr;

	line = ft_strdup("");
	if (!line)
		return (NULL);
	ptr = line;
	line = ft_strjoin(line, "A");
	if (!line)
	{
		free(ptr);
		return (NULL);
	}
	return (line);
}
