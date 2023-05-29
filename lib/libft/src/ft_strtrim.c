/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:02:27 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:36 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* returns a copy of ’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string */

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	end;

	if (!str || !set)
	{
		return (NULL);
	}
	while (*str && ft_strchr(set, *str))
		str++;
	end = ft_strlen(str);
	while (end && ft_strrchr(set, str[end]))
		end--;
	return (ft_substr(str, 0, end + 1));
}
