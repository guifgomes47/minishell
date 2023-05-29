/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:09:56 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:31 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* The bzero() function sets the first n bytes of the
area starting at str to zero */

void	ft_bzero(void *str, size_t nbyte)
{
	size_t			i;
	unsigned char	*zero;

	i = 0;
	zero = str;
	while (i < nbyte)
	{
		*(zero + i++) = '\0';
	}
}
