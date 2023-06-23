/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 06:06:21 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/23 02:18:31 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int parser_pipe(char *input, int index, t_data *data)
{
    int space;
    char *new_input;

    space = 0;
    if (input[index - 1] == ' ')
        space = 1;
    new_input = ft_strdup(&input[index + 1]);
    input[index - space] = '\0';
    return (handle_pipe(input, new_input, data));
}

int verify_caracter(char **input, int *i, t_data *data)
{
    if ((*input)[*i] == '\'')
    {
        (*i)++;
        while ((*input)[*i] != '\'')
            (*i)++;
    }
    else if ((*input)[*i] == '|')
    {
    }
}

int parser_input(char *input, t_data *data, int pipe, t_shell shell)
{
    int index;
    int count;

    index = 0;
    while (input[index])
    {
        if (input[index] == '"')
        {
            index++;
            while (input[index] != '"')
            {
                count = 0;
                while (input[index] == '\\' && ++index)
                    count++;
                if (input[index] == '$' && !(count % 2))
                    parser_var(&input, &index, data, shell);
                if (count && !(count % 2))
                    i--;
                i++;
            }
        }
        if (verify_caracter(char **input))
    }
}