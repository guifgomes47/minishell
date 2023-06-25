/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:40:05 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/25 05:18:05 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void ft_pwd(t_data *data)
{
    t_shell shell;

    ft_putstr_fd(data->dir, 1);
    ft_putstr_fd("\n", 1);
    shell.status = 0;
}
