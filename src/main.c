/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:23:59 by guilhfer          #+#    #+#             */
/*   Updated: 2023/06/25 07:38:10 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


int	main(int argc, char **argv, char **envp)
{
	t_data data;
	t_shell shell;
	char *line;

	(void)argc;
	(void)argv;
	init_data(&data, &shell, envp);
	if (!data.envp)
		exit(EXIT_FAILURE);
	shell.input = NULL;
	while (1)
	{
		shell.quit = 0;
		init_signal();
		line = readline("minishell> ");
		if (line == NULL)
		{
			printf("\n");
			break;
		}
		if (ft_strlen(line) > 0)
			add_history(line);
		init_parser(line, &data, &shell);
		free(line);
	}
	rl_clear_history();
	return (0);
}
