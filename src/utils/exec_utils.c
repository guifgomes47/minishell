/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:45:38 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/25 19:57:57 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**get_path(int aux, t_data *data, char *input)
{
	int		index;
	char	**paths;
	char	*str;
	char	*temp;

	index = 0;
	str = ft_strdup(&data->envp[aux][5]);
	paths = ft_split(str, ':');
	free(str);
	while (paths[index])
	{
		temp = paths[index];
		paths[index] = ft_strjoin(paths[index], "/");
		free(temp);
		temp = paths[index];
		paths[index] = ft_strjoin(paths[index], input);
		free(temp);
		index++;
	}
	return (paths);
}

int	verify_exec_path(char **input, t_data *data)
{
	int			index;
	int			aux;
	char		**paths;
	struct stat	statbuf;

	index = 0;
	statbuf.st_mode = 0;
	aux = search_index("PATH=", data);
	if (aux == -1)
		return (0);
	aux = search_index("PATH=", data);
	paths = get_path(aux, data, input[0]);
	while (paths[index])
	{
		stat(paths[index], &statbuf);
		if ((statbuf.st_mode & S_IXUSR) && !(statbuf.st_mode & __S_IFDIR))
		{
			free_env(paths);
			return (1);
		}
		index++;
	}
	free_env(paths);
	return (0);
}

int	verify_exec(char **input, t_data *data)
{
	int			ret;
	struct stat	statbuf;

	ret = 0;
	statbuf.st_mode = 0;
	stat(input[0], &statbuf);
	if (ft_strchr(input[0], '/') && (statbuf.st_mode & S_IXUSR)
		&& !(statbuf.st_mode & __S_IFDIR))
		ret = 1;
	else
		ret = verify_exec_path(input, data);
	return (ret);
}
