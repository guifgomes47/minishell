/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 06:06:21 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 04:54:43 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// A função é responsável por analisar uma entrada de comando que contém o caractere de pipe (|).
static int parser_pipe(char *input, int index, t_data *data)
{
    int space;
    char *new_input;

    space = 0;
    if (input[index - 1] == ' ')
        space = 1;
	// conten a parte da entrada após o caractere de pipe. 
    new_input = ft_strdup(&input[index + 1]);
    input[index - space] = '\0';
	// Chama a função abaixo para para lidar com a execução do comando com pipe. 
    return (handle_pipe(input, new_input, data));
}

// Responsável por analisar uma entrada de comando que contém o caractere de ponto e vírgula (;). 
static int parse_semicolon(char *input, int index, t_data *data)
{
    int space;
	int	status;
    char *new_input;
    t_shell shell;

    space = 0;
	status = shell.status;
    if (input[index - 1] == ' ')
        space = 1;
    new_input = ft_strdup(&input[index + 1]);
    input[index - space] = '\0';
    process_input(input, data, 0);
    if (status != 130)
        return (init_parser(new_input, data, &shell));
    else
        free(new_input);
    return (0);
}

// Verifica e lida com diferentes caracteres especiais em uma entrada de comando. 
int verify_caracter(char **input, int *index, t_data *data)
{
	t_shell shell;
	// verifica se o caractere atual é ', |, ; ou $ e executa ação correspondente para cada caso. 
    if ((*input)[*index] == '\'')
    {
        (*index)++;
        while ((*input)[*index] != '\'')
            (*index)++;
    }
    else if ((*input)[*index] == '|')
    {
        parser_pipe((*input), *index, data);
        return (1);
    }
    else if ((*input)[*index] == ';')
    {
        parse_semicolon((*input), *index, data);
        return (1);
    }
    else if ((*input)[*index] == '$')
        parser_var(input, index, data, &shell);
    (*index)++;
    return (0);
}

// Responsável por analisar uma entrada completa de comando.
int parser_input(char *input, t_data *data, int piped, t_shell *shell)
{
    int index;
    int count;

    index = 0;
	// A função percorre cada caractere da entrada de comando e realiza várias verificações e operações.
    while (input[index])
    {
		// Se encontrar aspas duplas ("), avança o índice até encontrar o próximo par de aspas duplas, lidando com caracteres de escape (\) e variáveis ($)
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
                    index--;
                index++;
            }
        }
        if (verify_caracter(&input, &index, data))
            return (0);
    }
	// processar a entrada de comando e retorna o resultado dessa chamada.
    return (process_input(input, data, piped));
}
