/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:18:14 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 18:51:26 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Esta função lida om os sinais enviados para o programa. 
void handle_signal(int signal)
{
	t_shell shell;
	
	// teclas Ctrl+C
    if (signal == SIGINT)
    {
		// define o status para indicar que o programa foi encerrado devido a um sinal SIGINT.
        shell.status = 130;
        if (shell.input)
            ft_putstr_fd("\nminishell>", 2);
			// Libera memoria se tiver algum registro de entrada
        if (shell.input)
            free(shell.input);
        shell.input = ft_strdup("\0");
    }
    else if (signal == SIGQUIT)
        write(2, "\b\b \b\b", 6); // usado para "apagar" a linha atual.
}

//  Inicializar o tratamento de sinais 
void init_signal(void)
{
    if (signal(SIGINT, handle_signal) == SIG_ERR)
        exit(EXIT_FAILURE);
    else if (signal(SIGQUIT, handle_signal) == SIG_ERR)
        exit(EXIT_FAILURE);
}
