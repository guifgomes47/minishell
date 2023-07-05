/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 02:49:23 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 19:14:08 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Responsável por lidar com o processo pai após a criação de um novo processo filho.
void handle_parent_process(char *input, t_data *data, int pid, int *fds)
{
    int fd;
    int status;
    t_shell shell;

// Aguarda o término do processo filho.
    if (waitpid(pid, &status, 0) != pid)
        exit(EXIT_FAILURE);
    // free(shell.input);
    // shell.input = NULL;
    fd = dup(0);
	// Duplica o descritor de arquivo de leitura do pipe (fds[0]) para o descritor de arquivo padrão (0), substituindo a entrada padrão pelo pipe.
    dup2(fds[0], 0);
	// Fecha os descritores de arquivo de leitura e escrita do pipe
    close(fds[0]);
    close(fds[1]);
    init_parser(input, data, &shell);
	free(input); //new
    dup2(fd, 0);
    close(fd);
}

// Responsável pela criação de um novo processo filho para lidar com a execução de comandos em um pipe. 
int handle_pipe(char *a, char *b, t_data *data)
{
    pid_t pid;
    int fds[2];

// Cria um pipe usando a função pipe(), armazenando os descritores de arquivo nos elementos do array fds.
    if (pipe(fds) < 0)
        exit(EXIT_FAILURE);
	// Cria um novo processo filho
    pid = fork();
	// Verifica se e o processo pai ou filho (0)
    if (pid == 0)
    {
        free(b);
        dup2(fds[1], 1);
        close(fds[0]);
        close(fds[1]);
        process_input(a, data, 1);
    }
	
    else if (pid < 0)
        exit(EXIT_FAILURE);
    else // se for o processo pai
    {
        // free(a);
        a = NULL;
        handle_parent_process(a, data, pid, fds);
    }
	return (0);
    // return (1);
}
