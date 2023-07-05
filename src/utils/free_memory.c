/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 23:49:44 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 03:07:08 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Função para diferentes tipos de liberação de memoria

void free_env(char **envp)
{
    int index;
    int len;

    index = 0;
    len = env_len(envp);
    while (index < len)
        free(envp[index++]);
    free(envp);
}

// Libera memoria da entrada de dados (comandos)
void free_input(char **input)
{
    int index;

    index = 0;
    // while (input[index])
    //     free(input[index++]);
	while (input[index] != NULL)
    {
        free(input[index]);
        index++;
    }
    free(input);
}

void free_memory(t_data *data, char *input)
{
    free_env(data->envp);
    free(input);
    free(data->dir);
    ft_putstr_fd("exit\n", 2);
    exit(EXIT_SUCCESS);
}
