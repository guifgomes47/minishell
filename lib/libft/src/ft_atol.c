/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:39:46 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:36 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*The atol() function converts the initial portion of the string
pointed to by nptr to long int. */

long int	ft_atol(const char *nptr)
{
	long int	i;
	long int	res;
	int			sin;

	i = 0;
	sin = 1;
	res = 0;
	while (ft_isspace(nptr[i]))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sin *= -1;
		}
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = (res * 10) + (nptr[i++] - '0');
	}
	return (res * sin);
}
