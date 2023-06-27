/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:24:48 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/25 19:36:16 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	verify_export(char *input)
{
	int	index;

	index = 0;
	if (ft_isdigit(input[index]))
		return (0);
	while (input[index] && input[index] != '=')
	{
		if (!ft_isalnum(input[index]) && input[index] != '_')
			return (0);
		index++;
	}
	return (1);
}

int	show_export(char **env)
{
	int	x;
	int	y;
	int	aux;

	x = -1;
	while (env[++x])
	{
		y = 0;
		aux = 1;
		ft_putstr_fd("declare -x ", 1);
		while (env[x][y])
		{
			if (env[x][y] == '\\' || env[x][y] == '\"' || env[x][y] == '$')
				write(1, "\\", 1);
			write(1, &env[x][y], 1);
			if (env[x][y] == '=' && aux-- == 1)
				write(1, "\"", 1);
			y++;
		}
		if (aux != 1)
			write(1, "\"", 1);
		write(1, "\n", 1);
	}
	return (1);
}
