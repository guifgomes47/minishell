/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:29:31 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/23 22:29:31 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int search_index(char *search, t_data *data)
{
    int x;
    int y;

    x = 0;
    while (data->envp[i])
    {
        y = 0;
        while (data->envp[x][y] && data->envp[x][y] == search[y] && search[y] != '\0' && search[y] != '=' &&
               data->envp[x][y] != '\0' && data->envp[x][y] != '=')
            y++;
        if ((data->envp[x][y] == '\0' || data->envp[x][y] == '=') &&
            (search[y] == '\0' || search[y] == '='))
            return (x);
        x++;
    }
    return (-1);
}

void replace_variable(char *var, t_data *data, int index)
{
    if (ft_strchr(var, '='))
    {
        free(data->envp[index]);
        data->envp[index] = ft_strdup(var);
    }
}

char **export_envp(char **env, char *exp)
{
    int index;
    char **aux;

    index = 0;
    aux = malloc(sizeof(char *) * (ft_strlen(env) + 1));
    if (!aux)
        exit(EXIT_FAILURE);
    while (env[index])
    {
        aux[index] = ft_strdup(env[index]);
        index++;
    }
    free_env(env);
    aux[index] = ft_strdup(exp);
    index++;
    aux[index] = NULL;
    return (aux);
}
