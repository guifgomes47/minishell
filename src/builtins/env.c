/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:58:50 by guilhfer          #+#    #+#             */
/*   Updated: 2023/06/27 14:17:48 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// int ft_haystack(char c, char *charset)
// {
// 	int i;

// 	i = 0;
// 	while (charset[i])
// 	{
// 		if (c == charset[i])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int ft_lstrstr(char *str, char *to_find)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (str[i])
// 	{
// 		j = 0;
// 		while (str[i + j] == to_find[j])
// 		{
// 			if (str[i + j + 1] == '=')
// 				return (i + j + 1);
// 			j++;
// 		}
// 		return (0);
// 	}
// 	return (0);
// }

// char *ft_path(char *str, char *charset, char *find)
// {
// 	int i;

// 	i = ft_lstrstr(str, find);
// 	if (!i)
// 		return (NULL);
// 	while (!ft_haystack(str[i], charset))
// 		i++;
// 	return (&str[i]);
// }

// char *get_tenv(t_list **tenv, char *var)
// {
// 	char *path;
// 	t_list *ptr;

// 	ptr = *tenv;
// 	printf("ptr tenv: %s", (char *)ptr->content);
// 	{
// 		path = ft_path(ptr->content, "=", var);
// 		if (path)
// 			return (path);
// 		ptr = ptr->next;
// 	}
// 	return (NULL);
// }

void	ft_env(char **env)
{
	int		x;
	int		y;
	char	*ptr;
	t_shell	shell;

	x = 0;
	while (env[x])
	{
		ptr = ft_strstr(env[x], "=");
		if (ptr)
		{
			y = 0;
			while (env[x][y])
			{
				write(1, &env[x][y], 1);
				y++;
			}
			ft_putchar('\n');
		}
		x++;
	}
	shell.status = 0;
}

// Essa função fara uma copia do array env, alocando,
// interando e colocando nulo no final.
char	**copy_env(char **envp)
{
	int		index;
	char	**env_dt;

	index = 0;
	env_dt = malloc(sizeof(char *) * env_len(envp));
	if (!env_dt)
		exit(EXIT_FAILURE);
	while (envp[index])
	{
		env_dt[index] = ft_strdup(envp[index]);
		index++;
	}
	env_dt[index] = 0;
	return (env_dt);
}
