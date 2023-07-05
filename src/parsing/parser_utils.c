/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:11:16 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 04:33:27 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// A função copia um caractere de escape do ponteiro src para o ponteiro dst, 
// substituindo as aspas simples (') pelo caractere de aspas duplas ("), ou vice-versa. Basicamente, ela escapa o caractere.
void escape_char(char **dst, char **src)
{
    char ctr;

    (*src)++;
    if (**src == '\'')
        ctr = '"';
    else
        ctr = '\'';
    *((*dst)++) = ctr;
    *((*dst)++) = *((*src)++);
    *((*dst)++) = ctr;
}

// A função copia os caracteres do ponteiro src para o ponteiro dst, até encontrar o caractere 
// ptr. Se o caractere ptr for aspas duplas ("), ela lida com caracteres de escape (precedidos 
// por \) e inverte a ação de escapar, enquanto copia os caracteres para dst.
void copy_ptr(char **src, char **dst, char ptr)
{
    int count;

    while (**src != ptr)
    {
        count = 0;
        while (**src == '\\' && ptr == '"')
        {
            *((*dst)++) = *((*src)++);
            count++;
        }
        if (count && !(count % 2))
            *((*dst)--) = *((*src)--);
        *((*dst)++) = *((*src)++);
    }
}

// A função a percorre o str e incrementa o valor de index a cada caractere encontrado, 
// até encontrar o caractere ptr. Se o caractere ptr for aspas duplas ("), 
// ela lida com caracteres de escape (precedidos por \) e ajusta o valor de index de acordo.
void ptr_size(char **str, int *index, char ptr)
{
    int count;

    while (**str != ptr && **str)
    {
        count = 0;
        while (ptr == '"' && **str == '\\')
        {
            (*index)++;
            (*str)++;
            count++;
        }
        if (count && !(count % 2))
        {
            (*str)--;
            (*index)--;
        }
        (*index)++;
        (*str)++;
    }
}
