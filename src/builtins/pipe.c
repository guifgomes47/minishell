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
        process_input()
    }
}