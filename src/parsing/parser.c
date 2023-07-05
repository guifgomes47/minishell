/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:38:29 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 04:17:40 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Realiza a copia e verifica várias condições, como espaços em branco consecutivos, 
// aspas (simples ou duplas) e caracteres de escape (''). 
void copy_input(char *dst, char *src)
{
    char ptr;

    while (*src)
    {
        if (*src == ' ' && (*(src + 1) == ' ' || *(src + 1) == '\0'))
            src++;
        else if (*src == '"' || *src == '\'')
        {
            *(dst++) = *src;
            ptr = *(src++);
            copy_ptr(&src, &dst, ptr);
            *(dst++) = *(src++);
        }
        else if (*src == '\\' && *(src + 1))
            escape_char(&dst, &src);
        else
            *(dst++) = *(src++);
    }
    *dst = '\0';
}

// Calcula o tamanho necessário para armazenar a entrada de dados depois de aplicar as transformações. 
static int input_size(char *str)
{
    int index;
    char ptr;

    index = 0;
    while (*str)
    {
        if (*str == ' ' && (*(str + 1) == ' ' || *(str + 1) == '\0'))
            str++;
        else if (*str == '\\' && (str += 2))
            index += 4;
        else if (*str == '"' || *str == '\'')
        {
            ptr = *(str++);
            ptr_size(&str, &index, ptr);
            if (!*str)
                return (-1);
            str++;
            index = index + 2;
        }
        else if (str++)
            index++;
    }
    return (index);
}

// Retorna a entrada de dados limpa, ou seja, com as transformações aplicadas. 
char *input_clear(char *str)
{
    int len;
    char *clean_input;
    char *start_str;

    start_str = str;
	// remove espaços em branco no início da string
    while (*str == ' ' && *str)
        str++;
	// calcular o tamanho necessário da nova string limpa.
    len = input_size(str);
    if (len == -1)
        return (0);
	// Caso contrário, aloca espaço suficiente
    clean_input = (char *)malloc((len + 1) * sizeof(char));
    if (!clean_input)
        exit(EXIT_FAILURE);
	// chama a função copy_input para copiar a entrada de dados limpa para a nova string. 
    copy_input(clean_input, str);
    free(start_str);
    return (clean_input);
}

// Função principal que inicia o processo de análise da entrada de dados
int init_parser(char *input, t_data *data, t_shell *shell)
{
    char *clean_input;

	// obtem a entrada de dados limpa. 
    clean_input = input_clear(input);
    shell->input = NULL;
    if (clean_input == 0)
    {
        ft_putstr_fd("The minishell does not support multiline.\n", 2);
        return (0);
    }
    if (!*clean_input)
    {
        free(clean_input);
        return (0);
    }
	// Traz resultado da análise da entrada.
    return (parser_input(clean_input, data, 0, shell));
}
