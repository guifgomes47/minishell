/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 05:50:02 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/25 03:11:38 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Inicializa
void init_data(t_data *data, t_shell *shell, char **envp)
{
    data->envp = copy_env(envp);
    data->dir = getcwd(NULL, 0);
    data->fd_input = 0;
    data->fd_output = 1;
    data->redirection = 1;
    shell->status = 0;
    shell->input = NULL;
}
