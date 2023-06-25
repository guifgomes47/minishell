/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:38:29 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/25 04:32:23 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

char *input_clear(char *str)
{
    int len;
    char *clean_input;
    char *start_str;

    start_str = str;
    while (*str == ' ' && *str)
        str++;
    len = input_size(str);
    if (len == -1)
        return (0);
    clean_input = (char *)malloc((len + 1) * sizeof(char));
    if (!clean_input)
        exit(EXIT_FAILURE);
    copy_input(clean_input, str);
    free(start_str);
    return (clean_input);
}

int init_parser(char *input, t_data *data, t_shell *shell)
{
    char *clean_input;

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
    return (parser_input(clean_input, data, 0, shell));
}
