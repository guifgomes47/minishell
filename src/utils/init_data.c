/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 05:50:02 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 03:04:10 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Inicializar algumas variáveis
void init_data(t_data *data, t_shell *shell, char **envp)
{
	// Realiza a cópia de env.
    data->envp = copy_env(envp);
	// Atribui à variável dir da estrutura data o diretório de trabalho atual
    data->dir = getcwd(NULL, 0);
	// Armazenar o descritor de arquivo de entrada.
    data->fd_input = 0;
	// Armazenar o descritor de arquivo de saida.
    data->fd_output = 1;
	// Utilizada para indicar se há redirecionamento de entrada ou saída no programa.
    data->redirection = 1;
	// utilizada para armazenar o status ou código de retorno do shell.
    shell->status = 0;
	// Armazena comandos de entrada
    shell->input = NULL;
}
