/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 06:33:26 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/23 15:56:24 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void action_for_input(char **command, t_data *data)
{
    if (!data->redirection)
    {
        data->redirection = 1;
        return;
    }
    if (!ft_strcmp(command[0], "echo"))
        ft_echo(command);
    else if (!ft_strcmp(command[0], "cd"))
        ft_cd(command, data);
    else if (!ft_strcmp(command[0], "pwd"))
        ft_pwd(data);
    // else if (!ft_strcmp(command[0], "export"))
    //     ft_export(inputs, data);
    // else if (!ft_strcmp(command[0], "unset"))
    //     ft_unset(inputs, data);
    else if (!ft_strcmp(command[0], "env"))
        ft_env(data->envp);
    // else if (!ft_strcmp(command[0], "exit"))
    //     ft_exit(inputs, data);
    // else
    //     ft_exec(inputs, data);
}

int process_input(char *input, t_data *data, int piped)
{
    char **command;
    int fds[2];

    if (parser_error(input))
    {
        free(input);
        return (0);
    }
    fds[0] = dup(1);
    fds[1] = dup(0);
    input = input_clear(input);
    parser_redirect(&input, data);
    input = input_clear(input);
    command = split_input(input);
    free(input);
    action_for_input(command, data);
}