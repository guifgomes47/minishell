/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:58:44 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 05:12:03 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Recebe, armazena as variáveis de ambiente  apos remoção e retorna 
char **unset_env(char **env, int index)
{
    int x;
    int y;
    char **aux;

    x = 0;
    y = 0;
    aux = malloc(sizeof(char *) * (env_len(env) - 1));
    if (!aux)
        exit(EXIT_FAILURE);
    while (env[x])
    {
        if (x != index)
        {
            aux[y] = ft_strdup(env[x]);
            y++;
        }
        x++;
    }
    free_env(env);
    x--;
    aux[x] = NULL;
    return (aux);
}

// Verifica e remove variáveis de ambiente, caso contrario retorna erro
void ft_unset(char **input, t_data *data)
{
    int index;
    int aux;

    index = 1;
    while (input[index])
    {
        if (verify_export(input[index]))
        {
            aux = search_index(input[index], data);
            if (aux > 0)
                data->envp = unset_env(data->envp, aux);
            index++;
        }
        else
            return (error_message("unset : not a valid identifier\n", 1));
    }
}
