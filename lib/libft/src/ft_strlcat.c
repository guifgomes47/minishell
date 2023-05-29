/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:20:20 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:36 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* The strcat() function appends the src string to the dest string, overwriting
the terminating null byte ('\0') at the end of dest, and then adds a
terminating null byte. */

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	e_size;

	i = 0;
	if (ft_strlen(dest) < size)
	{
		e_size = ft_strlen(src) + ft_strlen(dest);
		while (*dest)
		{
			dest++;
		}
		while (src[i] && i < size - (e_size - ft_strlen(src)) - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (e_size);
	}
	return (ft_strlen(src) + size);
}
