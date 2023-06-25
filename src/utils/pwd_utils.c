/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:05:42 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/25 03:42:07 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void handle_env_pwd(t_data *data)
{
    char *pwd;

    data->dir = getcwd(NULL, 0);
    if (search_index("PWD", data) >= 0)
    {
        pwd = ft_strjoin("PWD=", data->dir);
        replace_variable(pwd, data, search_index(pwd, data));
        free(pwd);
    }
    else
    {
        pwd = ft_strjoin("PWD=", data->dir);
        data->envp = export_envp(data->envp, pwd);
        free(pwd);
    }
}

void handle_env_oldpwd(t_data *data)
{
    char *pwd;
    char *oldpwd;

    if (search_index("OLDPWD", data) >= 0)
    {
        pwd = ft_strjoin("PWD=", data->dir);
        oldpwd = ft_strjoin("OLD", pwd);
        replace_variable(oldpwd, data, search_index("OLDPWD=", data));
        free(oldpwd);
        free(pwd);
    }
    else
        data->envp = export_envp(data->envp, "OLDPWD");
    free(data->dir);
}

int handle_pwd(t_data *data, char *input)
{
    char *pwd;
    char *aux;

    aux = getcwd(NULL, 0);
    if (!aux && input && ft_strcmp(".", input) == 0)
    {
        ft_putstr_fd("Error retrieving current directory\n", 2);
        pwd = data->dir;
        data->dir = ft_strjoin(pwd, "/.");
        free(pwd);
    }
    if (aux)
    {
        handle_env_pwd(data);
        handle_env_oldpwd(data);
    }
    free(aux);
    return (1);
}
