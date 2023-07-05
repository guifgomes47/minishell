/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:38:45 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 20:45:07 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// A função lê uma lista de argumentos (armazenados em inputs) e escreve na saída padrão. 
// Se "-n" for fornecida como o primeiro argumento, a função não adicionará uma quebra de 
// linha no final. Caso contrário, uma quebra de linha será adicionada.
void ft_echo(char **inputs)
{
    int index;
    int flag;
    t_shell shell;

    flag = 0;
    index = 1;
    shell.status = 0;
    while (inputs[index] && !ft_strcmp(inputs[index], "-n") && index++)
        flag = 1;
    while (inputs[index])
    {
        write(1, inputs[index], ft_strlen(inputs[index]));
        if (inputs[index + 1])
            write(1, " ", 1);
        index++;
    }
    if (!flag)
        write(1, "\n", 1);
}
