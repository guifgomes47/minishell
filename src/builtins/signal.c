/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:18:14 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/25 05:14:40 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void handle_signal(int sig)
{
    if (sig == SIGINT)
	{
        printf("\n");
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
}

void init_signal(void)
{
	signal(SIGINT, handle_signal);
    signal(SIGQUIT, SIG_IGN);
}
