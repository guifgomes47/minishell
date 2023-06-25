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
#include <term.h>
#include <curses.h>
#include <termios.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <dirent.h>
#include <readline/readline.h>

// refatorando
typedef struct s_data
{
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
	char *input;
} t_shell;

//|Utils
void handle_env_pwd(t_data *data);
void handle_env_oldpwd(t_data *data);
int handle_pwd(t_data *data, char *input);
void init_data(t_data *data, t_shell *shell, char **envp);
void free_env(char **envp);
void free_input(char **input);
void free_memory(t_data *data, char *input);
void close_fd(t_data *data);
int show_export(char **env);
int verify_export(char *input);
int verify_exec(char **input, t_data *data);
int verify_exec_path(char **input, t_data *data);
char **get_path(int aux, t_data *data, char *input);

//|Parsing
char **split_input(char *str);
char *split_str(char *str);
void new_split(char *str, char *dest, char crt);
int process_input(char *input, t_data *data, int piped);
void action_for_input(char **command, t_data *data);
int init_parser(char *input, t_data *data, t_shell *shell);
char input_clear(char *str);
void copy_input(char *dst, char *src);
void parser_var(char **input_addr, int *index, t_data *data, t_shell shell);
void ptr_size(char **str, int *index, char ptr);
void copy_ptr(char **src, char **dst, char ptr);
void escape_char(char **dst, char **src);
int parser_redirect(char **input, t_data *data);
void parser_redirect_quotes(char *str, int *index, char quote);
void delete_redirect(char **input_addr, int index, int count);
char *get_filename(char *str, int *position);
void filename_init(char *src, char *dest, int index, int len);
int parser_input(char *input, t_data *data, int piped, t_shell shell);
int verify_caracter(char **input, int *index, t_data *data);
int parser_error(char *str);
int redir_error(char *str, int *index, char c);
void skip_quotes(char *str, int *index);
void handle_redirect(char **input, int index, t_data *data);
void redirect(char *str, int index, char **input, int is_append, int op);
void msg_error(t_data *data, t_shell *shell);
int fd_is_append(int fd, int append, char *filename);
int get_name_size(char *str);

//|Buitins
void ft_unset(char **input, t_data *data);
char **unset_env(char **env, int index);
void init_signal(void);
void handle_signal(int signal, t_shell shell);
void ft_pwd(t_data *data);
int handle_pipe(char *a, char *b, t_data *data);
void handle_parent_process(char *input, t_data *data, int pid, int fd);
void ft_export(char **input, t_data *data);
void copy_export(t_data *data);
char **export_envp(char **env, char *exp);
void replace_variable(char *var, t_data *data, int index);
int search_index(char *search, t_data *data);
void ft_exit(char **command, t_data *data);
int is_number(char *str);
void error_message(char *str, int status);
void exit_pipe(t_data *data);
void ft_exec(char **input, t_data *data);
int exec_and_verify(char **input, t_data *data);
int execute(char **input, t_data *data);
void ft_env(char **env);
void ft_echo(char **inputs);
void ft_cd(char **command, t_data *data);
int cd_sub(t_data *data);
int cd_dir(t_data *data);

#endif