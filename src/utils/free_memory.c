/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 23:49:44 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/22 00:24:56 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void free_env(char **envp)
{
    int index;
    int len;

    index = 0;
    len = ft_strlen(envp);
    while (index < len)
        free(envp[index++]);
    free(envp);
}

void free_memory(t_data *data, char *input)
{
    free_env(data->envp);
    free(input);
    free(data->dir);
    ft_putstr_fd("exit\n", 2);
    exit(EXIT_SUCCESS);
}
