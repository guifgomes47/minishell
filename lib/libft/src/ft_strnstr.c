/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:35:45 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:36 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* The strnstr() function locates the first occurrence of the null-termi-
nated string find in the string scan, where not more than len characters
are searched. Characters that appear after a `\0' character are not
searched. */

char	*ft_strnstr(const char *scan, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (*find == '\0')
	{
		return ((char *)scan);
	}
	i = 0;
	j = ft_strlen(find);
	while (scan[i] && (i + j) <= len)
	{
		if (!ft_strncmp(&scan[i], find, j))
		{
			return ((char *)&scan[i]);
		}
		i++;
	}
	return (0);
}
