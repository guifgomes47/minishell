/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:23:59 by guilhfer          #+#    #+#             */
/*   Updated: 2023/06/27 17:47:48 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	t_shell	shell;
	char	*line;

	(void)argc;
	(void)argv;
	init_data(&data, &shell, envp);
	if (!data.envp)
		exit(EXIT_FAILURE);
	while (1)
	{
		shell.quit = 0;
		free(shell.input);
		init_signal();
		ft_putstr_fd("minishell>", 2);
		// fd = open(shell.input, O_RDONLY);
		line = get_next_line(0);
		if (!line)
			free_memory(&data, shell.input);
		else
			init_parser(line, &data, &shell);
	}
	return (0);
}
