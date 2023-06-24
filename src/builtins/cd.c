/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:49:53 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/23 21:49:53 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int cd_dir(t_data *data)
{
    if (search_index("HOME=", data) < 0 ||
        chdir((ft_strchr(data->envp[search_index("HOME=", data)], '=') + 1)) == -1)
        return (0);
    handle_pwd(data, NULL);
    return (1);
}

int cd_sub(t_data *data)
{
    if (search_index("OLDPWD=", data) < 0 ||
        chdir((ft_strchr(data->envp[search_index("OLDPWD=", data)], '=') + 1)) == -1)
        return (0);
    handle_pwd(data, NULL);
    return (1);
}

void ft_cd(char **command, t_data *data)
{
    t_shell *shell;

    if (command[1] && command[2])
        return (error_message("Error cd: too many arguments\n", 1));
    else if (!command[1])
    {
        if (!cd_dir(data))
            return (error_message("Error cd: HOME: is undefined\n", 1));
    } // Se command[1] for igual a "-", a função cd_minus é chamada.
    else if (ft_strcmp(command[1], "-") == 0)
    {
        if (!cd_sub(data))
            return (error_message("Error cd: OLDPWD: is undefined\n", 1));
    }
    else
    {
        if (!cd_path(command, data)
            return (error_message("Error cd: no such file or directory\n", 1));
    }
    shell->status = 0;
}
