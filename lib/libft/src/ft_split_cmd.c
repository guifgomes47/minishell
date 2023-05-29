/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:46:26 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/16 01:46:45 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#define QUOTE 34
#define APOSTROPHE 39

static int	isquote(char c)
{
	if (c == APOSTROPHE || c == QUOTE)
		return (1);
	return (0);
}

static int	count_word(char const *str, int c)
{
	int	index;

	index = 0;
	while (str[index] != '\0' && str[index] != c)
		index++;
	return (index);
}

static int	cmdlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	if (*s == APOSTROPHE)
		len = count_word(++s, APOSTROPHE);
	else if (*s == QUOTE)
		len = count_word(++s, QUOTE);
	else if (*s != c)
		len = count_word(s, c);
	return (len);
}

size_t	ft_split_cmd_count(char const *str, char c)
{
	size_t	count;
	size_t	len;

	count = 0;
	while (*str != '\0')
	{
		if (*str != c || *str == APOSTROPHE || *str == QUOTE)
		{
			count++;
			len = cmdlen(str, c);
			str += isquote(*str);
			str += len;
			str += isquote(*str);
		}
		else
			str++;
	}
	return (count);
}

char	**ft_split_cmd(char const *str, char c)
{
	size_t	i;
	size_t	len;
	char	**matrix;

	if (str == NULL)
		return (NULL);
	matrix = malloc(sizeof(char *) * (ft_split_cmd_count(str, c) + 1));
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		if (*str != c || isquote(*str))
		{
			len = cmdlen(str, c);
			str += isquote(*str);
			matrix[i++] = ft_substr(str, 0, len);
			str += len;
			str += isquote(*str);
		}
		else
			str++;
	}
	matrix[i] = NULL;
	return (matrix);
}
