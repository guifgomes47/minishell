/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:23:59 by guilhfer          #+#    #+#             */
/*   Updated: 2023/06/22 00:50:46 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <unistd.h>

// int minishell_loop(t_list **tenv, t_data *data, t_clear *clear)
// {
// 	t_list *temp;
// 	t_list *lex;

// 	if (!tenv)
// 		return (0);
// 	while (1)
// 	{
// 		reset_ok(data);
// 		if ((gather_input(data, tenv, clear, 1)) == -1)
// 			continue;
// 		lex = ft_lstrevsplit(data->lexer);
// 		temp = lex;
// 		clean_lex(temp);
// 	}
// 	return (data->handler);
// }

// int minishell(char **envp)
// {
// 	t_list **tenv;
// 	t_data *data;
// 	t_clear *clear;

// 	tenv = create_list(envp);
// 	if (!tenv)
// 		return (-1);
// 	data = data_alloc();
// 	if (!data)
// 		ft_lstclear(tenv);
// 	clear = clear_alloc(tenv, data);
// 	if (!clear)
// 		return (-1);
// 	if (!isatty(0))
// 	{
// 		data->path = get_tenv(tenv, "PATH");
// 	}
// 	printf("TENV: %s\n", data->path);
// 	return (minishell_loop(tenv, data, clear));
// }

int main(int argc, char **argv, char **envp)
{
	t_data data;
	t_shell shell;
	// int		gnl;

	(void)argc;
	(void)argv;
	init_data(&data, envp);
	shell->status = 0;
	shell->input = NULL;
	if (!data.envp)
		exit(EXIT_FAILURE);
	while (1)
	{
		shell->quit = 0;
		free(shell->input);
		init_signal();
		ft_putstr_fd("minishell >", 2);
		// gnl = get_next_line(0, &shell->input);
		if (!get_next_line(0, &shell->input))
			free_memory(&data, shell->input);
		else
			init_parser(shell->input, &data, &shell);
	}
	// printf("ENVP: %s\n", *envp);
	// printf("ARGV: %s\n", *argv);
	// if (!envp)
	// 	return (6);
	// if (!isatty(1))
	// 	exit(0);
	// return (minishell(envp));
	return (0);
}
