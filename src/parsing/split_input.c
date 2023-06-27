/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:42:02 by marvin            #+#    #+#             */
/*   Updated: 2023/06/25 19:36:30 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	substrings_account(char *str)
{
	size_t	count;
	size_t	index;
	char	aux;

	str--;
	index = 0;
	while (*(++str))
	{
		if (*str == '"' || *str == '\'')
		{
			aux = *(str++);
			while (*str != aux)
			{
				count = 0;
				while (*str == '\\' && aux == '"' && ++count)
					str++;
				if (count && !(count % 2))
					str++;
				str++;
			}
		}
		if (*str == ' ')
			index++;
	}
	return (index);
}

void	new_split(char *str, char *dest, char crt)
{
	while (*str != ' ' && *str)
	{
		if (*str == '\'')
		{
			crt = *(str++);
			while (*str != crt)
				*(dest++) = *(str++);
			str++;
		}
		else if (*str == '"')
		{
			crt = *(str++);
			while (*str != crt)
			{
				if (*str == '\\' && (*(str + 1) == crt || *(str + 1) == '\\'
						|| *(str + 1) == '$'))
					str++;
				*(dest++) = *(str++);
			}
			str++;
		}
		else
			*(dest++) = *(str++);
	}
	*dest = '\0';
}

char	*split_str(char *str)
{
	char	*dest;
	int		size;

	size = ft_strlen(str);
	dest = malloc((size + 1) * sizeof(char));
	if (!dest)
		exit(EXIT_FAILURE);
	new_split(str, dest, 0);
	return (dest);
}

static char	*next_input(char *str)
{
	char	aux;
	int		len;

	str--;
	while (*(++str))
	{
		if (*str == '"' || *str == '\'')
		{
			aux = *(str++);
			while (*str != aux)
			{
				len = 0;
				while (*str == '\\' && aux == '"' && ++len)
					str++;
				if (len && !(len % 2))
					str--;
				str++;
			}
		}
		if (*str == ' ')
			return (str + 1);
	}
	return (str);
}

char	**split_input(char *str)
{
	char	**input;
	int		index;
	int		len;

	len = substrings_account(str);
	input = malloc((len + 1) * sizeof(char *));
	if (!input)
		exit(EXIT_FAILURE);
	index = 0;
	while (index < len)
	{
		input[index++] = split_str(str);
		if (index > 0 && !input[index - 1])
			return (NULL);
		str = next_input(str);
	}
	input[index] = NULL;
	return (input);
}
