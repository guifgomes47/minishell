/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:07:37 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/27 13:45:58 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exit_pipe(t_data *data)
{
	t_shell	shell;

	free_input(data->envp);
	if (shell.input)
		free(shell.input);
	free(data->dir);
	exit(EXIT_SUCCESS);
}

void	error_message(char *str, int status)
{
	t_shell	shell;

	shell.status = status;
	status = status;
	ft_putstr_fd(str, 2);
}

int	is_number(char *str)
{
	int	index;

	index = 0;
	if (str[index] == '-')
		index++;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}

void	ft_exit(char **command, t_data *data)
{
	t_shell	shell;

	shell.status = 0;
	if (command[1])
	{
		if (is_number(command[1]))
		{
			if (command[2])
				return (error_message("Error exit: too many arguments\n", 2));
			shell.status = ft_atoi(command[1]);
			if (shell.status > 255)
				shell.status = 255;
			else if (shell.status < 0)
				shell.status = 255;
		}
		else
			error_message("\t\tError exit: numeric argument required\n", 2);
	}
	free_env(command);
	free(data->dir);
	free_env(data->envp);
	exit(shell.status);
}
