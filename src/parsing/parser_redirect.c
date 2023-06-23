/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:57:58 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/23 16:54:17 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *get_filename(char *str, int position)
{
    int index;
    int count;
    char *filename;

    index = get_name_size()
}

void parser_redirect_quotes(char *str, int *index, char quote)
{
    int count;

    while (str[*index] != quote)
    {
        count = 0;
        while (str[*index] == '\\' && quote == '"')
        {
            count++;
            (*index)++;
        }
        if (count && !(count % 2))
            (*index)--;
        (*index)++;
    }
}

int parser_redirect(char **input, t_data *data)
{
    int index;
    char *str;
    char quote;

    index = -1;
    str = *input;
    while (str[++index])
    {
        if (str[index] == '\'' || str[index] == '"')
        {
            quote = str[index];
            index++;
            parser_redirect_quotes(str, &index, quote);
        }
        if (str[index] == '>' || str[index] == '<')
        {
            handle_redirect()
        }
    }
}