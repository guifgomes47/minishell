/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 00:00:14 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/24 18:02:53 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The calloc() function allocates memory for an array
of nmemb elements of size bytes each and returns a pointer
to the allocated memory. The memory is set to zero.*/

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*mem;
	size_t	max;

	max = nitems * size;
	if (max != 0 && (max / nitems) != size)
		return (NULL);
	mem = malloc(max);
	if (!mem)
		return (NULL);
	ft_bzero(mem, max);
	return (mem);
}
