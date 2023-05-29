/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:01:21 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:36 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Returns an array of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter.*/

static int	ft_rows_count(char const *str, char c)
{
	int	rows;

	rows = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != c && *str)
			rows++;
		while (*str != c && *str)
			str++;
	}
	return (rows);
}

char	**ft_split(char const *str, char c)
{
	char	**matrix;
	int		rows;
	int		size;
	int		i;

	rows = ft_rows_count(str, c);
	matrix = ft_calloc(sizeof(char *), (rows + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		while (*str && *str == c)
			str++;
		if (ft_strchr(str, c))
			size = ft_strchr(str, c) - str;
		else
			size = ft_strlen(str);
		matrix[i] = ft_substr(str, 0, size);
		if (!matrix[i])
			return (0);
		str += size;
		i++;
	}
	return (matrix);
}
