/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:37:20 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 04:59:50 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// responsável por pular ou "ignorar" as aspas em uma str
void skip_quotes(char *str, int *index)
{
    char quote;

    quote = str[(*index)++];
    while (str[(*index)] != quote)
    {
        if (str[(*index)] == '\\' && quote == '"')
            (*index) += 2;
        else
            (*index)++;
    }
}

// verifica se há erros ou problemas de redirecionamento em uma string.
int redir_error(char *str, int *index, char c)
{
    int count;

    count = 0;
    while (str[(*index)] == c)
    {
        count++;
        (*index)++;
    }
    if ((c == '>' && count > 2) || (c == '<' && count > 1))
        return (1);//indicando um erro de redirecionamento
    while (str[(*index)] == ' ')
        (*index)++;
    if (!str[(*index)])
        return (1); 
    return (0);
}

// função principal responsável pelo processamento de erros em um comando
int parser_error(char *str)
{
    int index;
    t_shell shell;

    index = 0;
    while (str[index])
    {
        if (str[index] == '\\')
            index += 2;
        if (str[index] == '"' || str[index] == '\'')
            skip_quotes(str, &index);
        if (str[index] == '>' || str[index] == '<')
        {
            if (redir_error(str, &index, str[index]))
            {
                shell.status = 1;
                ft_putstr_fd("Error: wrong or unsupported redirection\n", 2);
                return (1);
            }
        }
        else
            index++;
    }
    return (0);
}
