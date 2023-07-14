/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:45:38 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/08 21:19:29 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//  funções relacionadas a manipulação de caminhos de arquivos e verificação de execução.

// Função responsavel por retornar um array que contem os caminhos de diretório necessários para executar um comando específico.
char **get_path(int aux, t_data *data, char *input)
{
    int index;
    char **paths;
    char *str;
    char *temp;
	// Apos comentar consegui ter acesso ao env
	// paths = NULL;
    // str = NULL;
    // temp = NULL;
	// if (aux >= 0)
	// {
		index = 0;
		// Extrai variável de ambiente relacionada ao caminho do diretório
		str = ft_strdup(&data->envp[aux][5]);
		// Dividida em várias substrings usando o caractere ':' como delimitador, criando um array de strings.
		paths = ft_split(str, ':');
		free(str);
		while (paths[index] != NULL)
		{
			temp = paths[index];
			paths[index] = ft_strjoin(paths[index], "/");
			free(temp);
			temp = paths[index];
			paths[index] = ft_strjoin(paths[index], input);
			free(temp);
			index++;
		}
	// }
    return (paths);
}
// {
//     int index;
//     char **paths;
//     char *str;
//     char *temp;

//     index = 0;
//     str = ft_strdup(&data->envp[aux][5]);
//     paths = ft_split(str, ':');
//     free(str);
//     while (paths[index])
//     {
//         temp = paths[index];
//         paths[index] = ft_strjoin(paths[index], "/");
//         free(temp);
//         temp = paths[index];
//         paths[index] = ft_strjoin(paths[index], input);
//         free(temp);
//         index++;
//     }
//     return (paths);
// }

// Verificar se o comando pode ser executado usando os caminhos de diretório relevantes.
int verify_exec_path(char **input, t_data *data)
{
    int index;
    int aux;
    char **paths;
    struct stat statbuf;

    index = 0;
    statbuf.st_mode = 0;
	// Chama a função search_index para encontrar o índice de uma variável de ambiente 
	// chamada "PATH" dentro da estrutura data.
    aux = search_index("PATH=", data);
    if (aux == -1)
        return (0);
    // aux = search_index("PATH=", data);
	// Chama a função get_path para obter uma matriz contendo os caminhos de diretório.
    paths = get_path(aux, data, input[0]);
    while (paths[index])
    {
		// Para verificar se cada caminho de diretório é executável.
        stat(paths[index], &statbuf);
		//  Se um caminho for encontrado que seja executável (permissão de usuário para execução e não um diretório), 
		// sera liberada a memória alocada para o array de strings paths e retorna 1.
        if ((statbuf.st_mode & S_IXUSR) && !(statbuf.st_mode & __S_IFDIR))
        {
            free_env(paths);
            return (1);
        }
        index++;
    }
    free_env(paths);
    return (0);
}

// Função e responsavel por verificar se um comando pode ser executado, a função retorna 
// 1 para confirmar que pode ser executado e 0 caso contrário.
int verify_exec(char **input, t_data *data)
{
    int ret;
    struct stat statbuf;

    ret = 0;
    statbuf.st_mode = 0;
	// Abaixo verifica se o elemento input[0] é um arquivo executavel
    stat(input[0], &statbuf); 
    if (ft_strchr(input[0], '/') && (statbuf.st_mode & S_IXUSR) &&
    !(statbuf.st_mode & __S_IFDIR))
        ret = 1; //Se for executavel retorna 1
    else
        ret = verify_exec_path(input, data);// Caso contrario chama a função abaixo para verificar se o comando pode ser executado usando os caminhos de diretório relevantes.
    return (ret);
}
