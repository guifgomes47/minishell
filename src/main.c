/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:23:59 by guilhfer          #+#    #+#             */
/*   Updated: 2023/07/14 21:56:08 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	t_shell	shell;
	char	*line;

	(void)argc;
	(void)argv;
	// inicializar as estruturas data e shell com valores
	init_data(&data, &shell, envp);
	// Se for nulo (indicando que os dados de ambiente não foram corretamente inicializados), o programa encerra com exit(EXIT_FAILURE)
	if (!data.envp)
		exit(EXIT_FAILURE);
	while (1)
	{
		// definido como 0 para indicar que o shell não deve sair.
		shell.quit = 0;
		// Para trartar dos sinais
		init_signal();
		// armazenar (readline le a linha de comando , e o resultado e armazenado em line) a linha de comando digitada pelo usuário.
		line = readline(">");
		// Se for pressionado Ctrl+D ou line for nulo, encerrar o programa, inserindo uma nova linha e interrompendo o loop com o (break).
		if (line == NULL)
		{
			printf("\n");
			break;
		}
		// Verifico se e um comando valido inserindo vendo o seu tamanho para armazenar na history
		if (ft_strlen(line) > 0)
			add_history(line);
		// Se a linha de comando for nula e liberada a memoria
		if (!line)
			free_memory(&data, shell.input);
		else
			init_parser(line, &data, &shell);
		// free_env(data.envp);
		// free(line);
	}
	rl_clear_history();
	return (0);
}
