/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:39:15 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/25 22:59:46 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	execute(char **input, t_data *data)
{
	int			index;
	int			aux;
	char		**path;
	struct stat	statbuf;

	index = 0;
	statbuf.st_mode = 0;
	aux = search_index("PATH=", data);
	path = get_path(aux, data, input[0]);
	while (path[index])
	{
		stat(path[index], &statbuf);
		if ((statbuf.st_mode & S_IXUSR) && (execve(path[index], input,
					data->envp) != -1))
			return (0);
		index++;
	}
	free_env(path);
	return (1);
}

int	exec_and_verify(char **input, t_data *data)
{
	int			index;
	struct stat	statbuf;

	statbuf.st_mode = 0;
	index = search_index("PATH=", data);
	stat(input[0], &statbuf);
	if (ft_strchr(input[0], '/') && (statbuf.st_mode & S_IXUSR)
		&& (execve(input[0], &input[0], data->envp) != -1))
		return (0);
	else if (index >= 0)
	{
		if (!execute(input, data))
			return (0);
	}
	return (1);
}

void	ft_exec(char **input, t_data *data)
{
	pid_t	pid;
	int		status;
	t_shell	shell;

	status = 0;
	if (!verify_exec(input, data))
		return (error_message("\t\tError: Unknown command\n", 127));
	pid = fork();
	if (pid == 0)
	{
		if (exec_and_verify(input, data) != 0)
			exit(errno);
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
		exit(EXIT_FAILURE);
	else
	{
		init_signal();
		waitpid(pid, &status, 0);
	}
	shell.status = WEXITSTATUS(status);
	shell.quit = 0;
	if (shell.quit)
		shell.status = 130;
}
