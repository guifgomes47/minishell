/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:39:15 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 20:08:50 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// A função executa o comando representado por input[0].
int execute(char **input, t_data *data)
{
    int index;
    int aux;
    char **path;
    struct stat statbuf;

    index = 0;
    statbuf.st_mode = 0;
    aux = search_index("PATH=", data);
	// faz uma busca pelo caminho correto do executável com base na variável de ambiente PATH
    path = get_path(aux, data, input[0]);
    while (path[index])
    {
        stat(path[index], &statbuf);
		// percorre cada caminho possível e tenta executar o comando
        if ((statbuf.st_mode & S_IXUSR) &&
            (execve(path[index], input, data->envp) != -1))
            return (0);
        index++;
    }
    free_env(path);
    return (1);
}

// A funçÃO verifica se o comando especificado em input[0] pode ser executado diretamente 
// pelo caminho absoluto, ou seja, se contém um "/" no nome do arquivo.
int exec_and_verify(char **input, t_data *data)
{
    int index;

    index = search_index("PATH=", data);
    if (ft_strchr(input[0], '/') != NULL && (access(input[0], X_OK) == 0))
        return (execve(input[0], input, data->envp));
    else if (index >= 0)
    {
        if (!execute(input, data))
            return (0);
    }
    return (-1);
}
// {
//     int index;
//     struct stat statbuf;

//     statbuf.st_mode = 0;
//     index = search_index("PATH=", data);
//     stat(input[0], &statbuf);
//     if (ft_strchr(input[0], '/') && (statbuf.st_mode & S_IXUSR) &&
//         (execve(input[0], &input[0], data->envp) != -1))
//         return (0);
//     else if (index >= 0)
//     {
//         if (!execute(input, data))
//             return (0);
//     }
//     return (1);
// }

// 	Esta função criara um processo filho usando a função fork() e executar o comando especificado 
// em input[0] no processo filho. 
void ft_exec(char **input, t_data *data)
{
    pid_t pid;
    int status;
    t_shell shell;

    status = 0;
	// Verifica se o comando evalido
    if (!verify_exec(input, data))
        return (error_message("\t\tError: Unknown command\n", 127));
    pid = fork();
	// Se for o processo filho
    if (pid == 0)
    {
		// Para executar o comando.Se a execução for bem-sucedida, o processo filho termina com o 
		// código de saída 0 (EXIT_SUCCESS). Caso contrário, termina com o código de saída 
		// correspondente ao erro ocorrido. 
        if (exec_and_verify(input, data) != 0)
            exit(errno);
        exit(EXIT_SUCCESS);
    }
    else if (pid < 0)
        exit(EXIT_FAILURE);
    else // no processo pai
    {
        init_signal();
		// espera o processo filho terminar 
        waitpid(pid, &status, 0);
    }
    shell.status = WEXITSTATUS(status);
	// Se o encerramento "quit" for true define o status de saida com 130.
    if (shell.quit)
        shell.status = 130;
}
