/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:24:48 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 03:34:19 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Verifica se input atende aos critérios para ser exportada como uma variável de ambiente. 
int verify_export(char *input)
{
    int index;

    index = 0;
	// Verifica se e um digito, se for retorna 0 indicando que não pode ser exportada
    if (ft_isdigit(input[index]))
        return (0);
		// Intera para localizar o caracter '='
    while (input[index] && input[index] != '=')
    {
		// verifica se cada caractere é alfanumérico ou underscore ('_'), se for retorna 0 indicando que não pode ser exportada
        if (!ft_isalnum(input[index]) && input[index] != '_')
            return (0);
        index++;
    }
	// Retorna 1, para informar que atende aos critérios e pode ser exportada.
    return (1); 
}

// Função exibe as variáveis de ambiente no formato esperado
int show_export(char **env)
{
    int x;
    int y;
    int aux;

    x = -1;
    while (env[++x])
    {
        y = 0;
        aux = 1;
        ft_putstr_fd("declare -x ", 1);
        while (env[x][y])
        {
            if (env[x][y] == '\\' || env[x][y] == '\"' || env[x][y] == '$')
                write(1, "\\", 1);
            write(1, &env[x][y], 1);
            if (env[x][y] == '=' && aux-- == 1)
                write(1, "\"", 1);
            y++;
        }
        if (aux != 1)
            write(1, "\"", 1);
        write(1, "\n", 1);
    }
    return (1);
}
