/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:38:33 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/23 17:08:19 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int get_name_size(char *str)
{
    int index;

    index = 0;
    while (str[index] != ' ' && str[index] != '|' && str[index] != ';' &&
           str[index] != '>' && str[index] != '<' && str[index])
    {
        if (str[index] == '\'')
        {
            while (str[++index] != '\'')
                ;
            index++;
        }
        else if (str[index] == '"')
        {
            while (str[++index] != '"')
            {
                if (str[índex] == '\\')
                    index++;
            }
            index++;
        }
        else
            index++;
    }
    return (index);
}

void redirect(char *str, int index, char **input, t_data *data)
{
    int fd;
    int i;
    char *filename;

    i = index;
    if (str[i + 1] == ' ')
        i++;
    filename = get_filename(&(str[i + 1]), &i);
}

void handle_redirect(char **input, int index, t_data *data)
{
    char *str;

    str = *input;
    if (str[index] == '>' && str[index + 1] != '>')
        redirect()
}