/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:01:21 by guilhfer          #+#    #+#             */
/*   Updated: 2023/06/10 20:20:36 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* Returns an array of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter.*/

static int	ft_rows_count(char const *str)
{
	int	rows;

	rows = 0;
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		if (!ft_isspace(*str) && *str)
			rows++;
		while (*str && !ft_isspace(*str))
			str++;
	}
	return (rows);
}

void	free_array(char **matrix)
{
	int	i;

	if (matrix)
	{
		i = 0;
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

char	**ft_split_and_cpy(char const *str, char **substring, char *memory)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (ft_isspace(*str))
			str++;
		memory = (char *)str;
		while (*str && !ft_isspace(*str))
			str++;
		substring[i] = (char *)ft_calloc(sizeof(char), str - memory + 2);
		if (!substring[i])
		{
			free_array(substring);
			return (NULL);
		}
		ft_memcpy(substring[i], memory, str - memory);
		i++;
	}
	substring[i] = 0;
	return (substring);
}

char	**ft_tokenize(char const *str)
{
	char	**substring;
	char	*memory;

	memory = (char *)str;
	substring = (char **)malloc(sizeof(char *) * (ft_rows_count(str) + 1));
	if (!substring || !str)
		return (NULL);
	return (ft_split_and_cpy(str, substring, memory));
}
