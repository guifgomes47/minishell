/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:13:13 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/24 18:13:13 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void close_fd(t_data *data)
{
    if (data->fd_input != 0)
    {
        close(data->fd_input);
        data->fd_input = 0;
    }
    if (data->fd_output != 1)
    {
        close(data->fd_output);
        data->fd_output = 1;
    }
}
