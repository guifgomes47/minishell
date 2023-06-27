/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:18:14 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/27 14:04:18 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_signal(int signal)
{
	t_shell	shell;

	if (signal == SIGINT)
	{
		shell.input = 0;
		shell.status = 130;
		if (shell.input)
			ft_putstr_fd("\nminishell>", 2);
		if (shell.input)
			free(shell.input);
		shell.input = ft_strdup("\0");
	}
	else if (signal == SIGQUIT)
		write(2, "\b\b \b\b", 6);
}

void	init_signal(void)
{
	if (signal(SIGINT, handle_signal) == SIG_ERR)
		exit(EXIT_FAILURE);
	else if (signal(SIGQUIT, handle_signal) == SIG_ERR)
		exit(EXIT_FAILURE);
}
