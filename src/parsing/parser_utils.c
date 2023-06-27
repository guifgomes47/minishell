/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:11:16 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/25 19:36:40 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	escape_char(char **dst, char **src)
{
	char	ctr;

	(*src)++;
	if (**src == '\'')
		ctr = '"';
	else
		ctr = '\'';
	*((*dst)++) = ctr;
	*((*dst)++) = *((*src)++);
	*((*dst)++) = ctr;
}

void	copy_ptr(char **src, char **dst, char ptr)
{
	int	count;

	while (**src != ptr)
	{
		count = 0;
		while (**src == '\\' && ptr == '"')
		{
			*((*dst)++) = *((*src)++);
			count++;
		}
		if (count && !(count % 2))
			*((*dst)--) = *((*src)--);
		*((*dst)++) = *((*src)++);
	}
}

void	ptr_size(char **str, int *index, char ptr)
{
	int	count;

	while (**str != ptr && **str)
	{
		count = 0;
		while (ptr == '"' && **str == '\\')
		{
			(*index)++;
			(*str)++;
			count++;
		}
		if (count && !(count % 2))
		{
			(*str)--;
			(*index)--;
		}
		(*index)++;
		(*str)++;
	}
}
