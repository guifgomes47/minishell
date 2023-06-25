/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 02:49:23 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/23 06:34:00 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void handle_parent_process(char *input, t_data *data, int pid, int fd)
{
    int fd;
    int status;
    t_shell *shell;

    if (waitpid(pid, &status, 0) != pid)
        exit(EXIT_FAILURE);
    free(shell->input);
    shell->input = NULL;
    fd = dup(0);
    dup2(fd[0], 0);
    close(fd[0]);
    close(fd[1]);
    init_parser(input, data, shell);
    dup2(fd, 0);
    close(fd);
}

int handle_pipe(char *a, char *b, t_data *data)
{
    pid_t pid;
    int fds[2];

    if (pipe(fds) < 0)
        exit(EXIT_FAILURE);
    pid = fork();
    if (pid == 0)
    {
        free(b);
        dup2(fds[1], 1);
        close(fds[0]);
        close(fds[1]);
        process_input(a, data, 1);
    }
    else if (pid < 0)
        exit(EXIT_FAILURE);
    else
    {
        free(a);
        a = NULL;
        handle_parent_process(a, data, pid, fds);
    }
    return (1);
}
