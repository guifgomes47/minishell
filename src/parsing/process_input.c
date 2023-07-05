/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 06:33:26 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 04:03:24 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// A função toma uma ação com base no comando de entrada e nos dados fornecidos. 
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
    else if (!ft_strcmp(command[0], "export"))
        ft_export(command, data);
    else if (!ft_strcmp(command[0], "unset"))
        ft_unset(command, data);
    else if (!ft_strcmp(command[0], "env"))
        ft_env(data->envp);
    else if (!ft_strcmp(command[0], "exit"))
        ft_exit(command, data);
    else
        ft_exec(command, data);
}

// Processa a entrada de comando fornecida.
int process_input(char *input, t_data *data, int piped)
{
    char **command;
    int fds[2];

	// Verifica se ocorreu algum erro durante a análise do comando com a função 
    if (parser_error(input))
    {
        free(input);
        return (0);
    }
    fds[0] = dup(1);
    fds[1] = dup(0);
    input = input_clear(input);
	// Realiza o redirecionamento da entrada 
    parser_redirect(&input);
    input = input_clear(input);
	// Divide a entrada de comando em um array de strings 
    command = split_input(input);
    free(input);
    action_for_input(command, data);
    // free_input(command);
	// Restaura os descritores de arquivo padrão
    dup2(fds[0], 1);
    dup2(fds[1], 1);
	// Fecha os descritores de arquivo duplicados em fds[0] e fds[1].
    close_fd(data);
    close(fds[0]);
    close(fds[1]);
    if (piped)
        exit_pipe(data);
    return (0);
}
