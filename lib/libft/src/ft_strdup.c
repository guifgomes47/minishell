/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:21:38 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:36 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//The ft_strdup() function returns a pointer to the duplicated string,
//	or NULL if insufficient memory was available.

char	*ft_strdup(const char *str)
{
	char	*cpy;
	size_t	size;

	size = ft_strlen(str) + 1;
	cpy = malloc(sizeof(char) * size);
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, str, size);
	return (cpy);
}
