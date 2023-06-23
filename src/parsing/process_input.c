/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 06:33:26 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/23 15:56:24 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int process_input(char *input, t_data *data, int piped)
{
    char **inputs;
    int fds[2];

    if (parser_error(input))
    {
        free(input);
        return (0);
    }
    fds[0] = dup(1);
    fds[1] = dup(0);
    input = input_clear(input);
    parser_redirect()
}