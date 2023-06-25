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
        while (data->envp[x][y] && data->envp[x][y] == search[y] &&
               search[y] != '\0' && search[y] != '=' &&
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

void copy_export(t_data *data)
{
    char **temp;
    char *swap;
    int index;
    int position;

    index = 0;
    temp = duplicate_envp(data->envp);
    while (temp[index + 1])
    {
        position = index + 1;
        if (ft_strcmp(temp[index], temp[position]) > 0)
        {
            swap = temp[position];
            temp[position] = temp[index];
            temp[index] = swap;
            index = 0;
        }
        else
            index++;
    }
    show_export(temp);
    free_envp(temp);
}

void ft_export(char **input, t_data *data)
{
    int index;
    int len;
    t_shell *shell;

    index = 1;
    len = ft_strlen(input);
    if (input[index])
    {
        while (input[index] != '\0')
        {
            len = search_index(input[index], data);
            if (len >= 0 && verify_export(input[index]))
                replace_variable(input[index], data, len);
            else if (verify_export(input[index]))
            {
                data->envp = export_envp(data->envp, input[index]);
                if (!data->envp)
                    exit(EXIT_FAILURE);
            }
            else
                return (error_message("export: bad identifier\n", 1));
            index++;
        }
    }
    else
        copy_export(data);
    shell->status = 0;
}
