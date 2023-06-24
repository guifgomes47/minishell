/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:23:59 by guilhfer          #+#    #+#             */
/*   Updated: 2023/06/22 00:50:46 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
	t_data data;
	t_shell shell;

	(void)argc;
	(void)argv;
	init_data(&data, envp);
	shell->status = 0;
	shell->input = NULL;
	if (!data.envp)
		exit(EXIT_FAILURE);
	while (1)
	{
		shell->quit = 0;
		free(shell->input);
		init_signal();
		ft_putstr_fd("minishell >", 2);
		if (!get_next_line(0, &shell->input))
			free_memory(&data, shell->input);
		else
			init_parser(shell->input, &data, &shell);
	}

	return (0);
}
