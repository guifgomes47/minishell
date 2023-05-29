/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea1_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:59:58 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/27 23:40:06 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_lstadd_new(t_list **list, void *content)
{
	t_list	*new;

	if (content)
	{
		new = ft_lstnew(content);
		ft_lstadd_back(list, new);
	}
}

void	add_env_var(char **envp, t_list **tmp)
{
	int		i;
	char	cwd[1024];
	char	*launch;

	i = 0;
	getcwd(cwd, sizeof(cwd));
	printf("CWD ENV: %s\n", cwd);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "_=", 2) != 0)
			ft_lstadd_new(tmp, envp[i]);
		else
		{
			launch = ft_strjoin("_=", cwd);
			if (!launch)
				return ;
			ft_lstadd_new(tmp, launch);
		}
		i++;
	}
}

t_list	**create_list(char **envp)
{
	t_list	**tmp;
	char	*pwd;
	char	cwd[1024];

	tmp = (t_list **)ft_calloc(sizeof(t_list *), 1);
	if (!tmp)
		return (NULL);
	getcwd(cwd, sizeof(cwd));
	if (!envp[0])
	{
		pwd = ft_strjoin("PWD=", cwd);
		ft_lstadd_new(tmp, "SHLVL=1");
		ft_lstadd_new(tmp, pwd);
		return (tmp);
	}
	add_env_var(envp, tmp);
	return (tmp);
}
