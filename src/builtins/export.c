/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:29:31 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/07 03:22:44 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Esta fdunção busca por uma string que seja igual à string de busca. Se encontrar 
// uma correspondência, retorna o índice onde a correspondência foi encontrada no array envp. 
// Caso contrário, retorna -1.
int search_index(char *search, t_data *data)
{
    int x;
    int y;

    x = 0;
    while (data->envp[x])
    {
        y = 0;
        while (data->envp[x][y] && data->envp[x][y] == search[y] 
		&& search[y] != '\0' && search[y] != '=' &&
        data->envp[x][y] != '\0' && data->envp[x][y] != '=')
            y++;
        if ((data->envp[x][y] == '\0' || data->envp[x][y] == '=') &&
        (search[y] == '\0' || search[y] == '='))
            return (x);
        x++;
    }
    return (-1);
}

// A função substitui a string no índice especificado no array envp dentro da estrutura data pela string var.
void replace_variable(char *var, t_data *data, int index)
{
    if (ft_strchr(var, '='))
    {
        free(data->envp[index]);
        data->envp[index] = ft_strdup(var);
    }
}

// Esta função novo array aux e copia env para o aux e o retorna
char **export_envp(char **env, char *exp)
{
    int index;
    char **aux;

    index = 0;
    aux = malloc(sizeof(char *) * (env_len(env) + 1));
    if (!aux)
        exit(EXIT_FAILURE);
    while (env[index])
    {
        aux[index] = ft_strdup(env[index]);
        index++;
    }
    free_env(env);
    aux[index] = ft_strdup(exp);
    index++;
    aux[index] = NULL;
    return (aux);
}

// A função cria uma cópia do array de strings envp dentro da estrutura data e armazena 
// essa cópia em uma variável temmporária temp. Em seguida, classifica o array temp em ordem 
// alfabética usando o algoritmo de ordenação "bubble sort". Após a classificação, chama uma 
// função show_export para exibir o conteúdo do array.
void copy_export(t_data *data)
{
    char **temp;
    char *swap;
    int index;
    int position;

    index = 0;
    temp = copy_env(data->envp);
    while (temp[index + 1])
    {
        position = index + 1;
        if (ft_strcmp(temp[index], temp[position]) > 0)
        {
            swap = temp[position];
            temp[position] = temp[index];
            temp[index] = swap;
            index = 0;
        }
        else
            index++;
    }
    show_export(temp);
    free_env(temp);
}

// Esta função lida com a exportação de variáveis de ambiente. Se houver argumentos no array 
// input, a função itera sobre eles. Para cada argumento e verifica se ele já existe no array 
// envp e se é uma variável válida para exportação. Se for o caso, substitui a variável 
// existente pelo novo valor. Caso contrário, adiciona a nova variável ao array envp. 
// Se nenhum argumento for fornecido, a função chama a função copy_export para copiar e 
// classificar o array envp, exibindo-o em seguida.
void ft_export(char **input, t_data *data)
{
    int index;
    int len;
    t_shell shell;

    index = 1;
    if (input[index])
    {
        while (input[index])
        {
            len = search_index(input[index], data);
            if (len >= 0 && verify_export(input[index]))
                replace_variable(input[index], data, len);
            else if (verify_export(input[index]))
            {
                data->envp = export_envp(data->envp, input[index]);
                if (!data->envp)
                    exit(EXIT_FAILURE);
            }
            else
                return (error_message("export: bad identifier\n", 1));
            index++;
        }
    }
    else
        copy_export(data);
    shell.status = 0;
}
