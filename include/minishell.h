/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:40:24 by guilhfer          #+#    #+#             */
/*   Updated: 2023/06/10 21:37:11 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/include/libft.h"
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	int		size;
	int		child;
	int		free;
	int		checker;
	char	*path;
	char	*buffer;
	char	**lexer;
	int		handler;
}			t_data;

typedef struct s_clear
{
	t_data	*data;
	t_list	**tenv;
	int		first;
}			t_clear;

//|Utils
t_list		**create_list(char **envp);
t_data		*data_alloc(void);
char		**ft_tokenize(char const *str);

//|Buitins
char		*get_tenv(t_list **tenv, char *var);

//|Main utils
void		reset_ok(t_data *data);
void		clean_lex(t_list *lex);
t_clear		*clear_alloc(t_list **tenv, t_data *data);

//|Parsing
int			gather_input(t_data *data, t_list **tenv, t_clear *clear, int flag);

//|Prompt
char		*prompt_shell(void);
char		*check_prompt(t_clear *clear);
char		*choose_prompt(t_clear *clear);

#endif