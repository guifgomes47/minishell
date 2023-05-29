/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:23:59 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/29 00:44:43 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <unistd.h>

int	minishell_loop(t_list **tenv, t_data *data, t_clear *clear)
{
	t_list	*temp;
	t_list	*lex;

	if (!tenv)
		return (0);
	while (1)
	{
		reset_ok(data);
		if ((gather_input(data, tenv, clear, 1)) == -1)
			continue ;
		lex = ft_lstrevsplit(data->lexer);
		temp = lex;
		clean_lex(temp);
	}
	return (data->handler);
}

int	minishell(char **envp)
{
	t_list	**tenv;
	t_data	*data;
	t_clear	*clear;

	tenv = create_list(envp);
	if (!tenv)
		return (-1);
	data = data_alloc();
	if (!data)
		ft_lstclear(tenv);
	clear = clear_alloc(tenv, data);
	if (!clear)
		return (-1);
	if (!isatty(0))
	{
		data->path = get_tenv(tenv, "PATH");
	}
	printf("TENV: %s\n", data->path);
	return (minishell_loop(tenv, data, clear));
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	printf("ENVP: %s\n", *envp);
	printf("ARGV: %s\n", *argv);
	if (!envp)
		return (6);
	if (!isatty(1))
		exit(0);
	return (minishell(envp));
}
