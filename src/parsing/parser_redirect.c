/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:57:58 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 04:42:16 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Esta função é responsável por extrair o nome de um arquivo a partir de uma 
// string de origem (src) e armazená-lo em uma string de destino (dest). 
void filename_init(char *src, char *dest, int index, int len)
{
    while (src[index] != ' ' && src[index] != '|' && src[index] != ';' &&
           src[index] != '>' && src[index] != '<' && src[index])
    {
        if (src[index] == '\'')
        {
            while (src[++index] != '\'')
                dest[len++] = src[index];
            index++;
        }
        else if (src[index] == '"')
        {
            while (src[++index] != '"')
            {
                if (src[index] == '\\')
                    index++;
                dest[len++] = src[index];
            }
            index++;
        }
        else
            dest[len++] = src[index++];
    }
    dest[len] = '\0';
}

char *get_filename(char *str, int *position)
{
    int index;
    int count;
    char *filename;

    index = get_name_size(str);
    *position += index;
    filename = (char *)malloc(sizeof(char) * (index + 1));
    if (!filename)
        return (NULL);
    index = 0;
    count = 0;
	// extrair o nome de um arquivo
    filename_init(str, filename, index, count);
    return (filename);
}

// Esta função é responsável por remover uma parte da string de entrada (*input_addr). 
void delete_redirect(char **input_addr, int index, int count)
{
    char *input;
    char *tmp;

    tmp = ft_substr(input_addr[0], 0, index);
    input = ft_strjoin(tmp, &(input_addr[0][count + 1]));
    free(tmp);
    free(*input_addr);
    *input_addr = input;
}

// Esta função é usada para lidar com as aspas simples (''') e aspas duplas ('"') 
// durante o processo de análise de redirecionamento. Lida com os caracteres de escape ('') 
// que podem estar presentes dentro das aspas duplas, permitindo que sejam tratados corretamente.
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

// Esta função é responsável por analisar uma string de entrada (*input) 
// em busca de redirecionamentos. 
int parser_redirect(char **input)
{
    int index;
    char *str;
    char quote;

    index = -1;
    str = *input;
    while (str[++index])
    {
		// percorre a string, verificando se há ocorrências de aspas simples 
		// (''') ou aspas duplas ('"') para lidar corretamente com caracteres de escape
        if (str[index] == '\'' || str[index] == '"')
        {
            quote = str[index];
            index++;
            parser_redirect_quotes(str, &index, quote);
        }
        if (str[index] == '>' || str[index] == '<')
        {
            handle_redirect(input, index);
            return (1);
        }
        if (str[index] == '\\')
            index++;
    }
    return (0);
}
