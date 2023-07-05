/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:07:37 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 19:51:04 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void exit_pipe(t_data *data)
{
    t_shell shell;

    // free_input(data->envp);
    if (shell.input)
        free(shell.input);
    free(data->dir);
    exit(EXIT_SUCCESS);
}

// Define o status e exibe mensagem de erro
void error_message(char *str, int status)
{
    t_shell shell;

    shell.status = status;
	perror(str);
    // ft_putstr_fd(str, 2);
}

// Verifica se e um numero
int is_number(char *str)
{
    int index;

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

// Função lida com o comando "exit", ela verifica os argumentos fornecidos ao comando 
// e define o status de saída do shell com base nos argumentos. 
void ft_exit(char **command, t_data *data)
{
    t_shell shell;

    shell.status = 0;
    if (command[1])
    {
        if (is_number(command[1]))
        {
			// Se houver mais de um argumento, uma mensagem de erro é exibida. 
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
