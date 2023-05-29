/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:10:26 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:36 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Applies the function ’f’ to each character of the string ’s’, and passing
its index as first argument to create a new string */

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*dest;
	int		i;

	if (!str)
		return (NULL);
	dest = ft_strdup((char *)str);
	if (!dest)
		return (NULL);
	i = 0;
	while (dest[i])
	{
		dest[i] = f(i, dest[i]);
		i++;
	}
	return (dest);
}
