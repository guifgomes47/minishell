/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:22:05 by guilhfer          #+#    #+#             */
/*   Updated: 2023/06/10 20:15:48 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	execute_parsing(t_data *data, t_list **tenv)
{
	int	i;

	data->lexer = ft_tokenize(data->buffer);
	if (data->lexer == NULL)
		return (0);
	i = 0;
	while (data->lexer[i])
	{
		if (data->lexer[i])
			printf("LEXER [%d]: %s\n", i, data->lexer[i]);
		i++;
	}
	tenv = tenv;
	return (1);
}

int	print_prompt(t_data *data, t_list **tenv, t_clear *clear)
{
	char	*line;

	data->lexer = NULL;
	line = choose_prompt(clear);
	if (data->checker == -1 || !line)
		data->buffer = readline("minishell > ");
	else
		data->buffer = readline(line);
	printf("BUFFER: %s\n", data->buffer);
	if (line)
		free(line);
	if (data->buffer && !data->buffer[0])
		return (-1);
	if (tenv)
		free(tenv);
	return (1);
}

int	gather_input(t_data *data, t_list **tenv, t_clear *clear, int flag)
{
	if (flag == 1)
	{
		if (print_prompt(data, tenv, clear) == -1)
			return (-1);
		if (execute_parsing(data, tenv) == -1)
			return (-1);
	}
	return (1);
}
