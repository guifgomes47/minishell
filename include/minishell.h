/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:40:24 by guilhfer          #+#    #+#             */
/*   Updated: 2023/06/22 00:20:57 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "../lib/libft/include/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

typedef struct s_data
{
	int size;
	int child;
	int free;
	int checker;
	char *path;
	char *buffer;
	char **lexer;
	int handler;
	// refatorando
	char **envp;
	char *dir; // pwd
	int fd_output;
	int fd_input;
	int redirection;
} t_data;

// refatorando
typedef struct s_shell
{
	int status;
	int quit;
	char input;
} t_shell;

typedef struct s_clear
{
	t_data *data;
	t_list **tenv;
	int first;
} t_clear;

//|Utils
t_list **create_list(char **envp);
t_data *data_alloc(void);

//|Buitins
char *get_tenv(t_list **tenv, char *var);

//|Main utils
void reset_ok(t_data *data);
void clean_lex(t_list *lex);
t_clear *clear_alloc(t_list **tenv, t_data *data);

//|Parsing
int gather_input(t_data *data, t_list **tenv, t_clear *clear, int flag);

//|Prompt
char *prompt_shell(void);
char *check_prompt(t_clear *clear);
char *choose_prompt(t_clear *clear);

#endif