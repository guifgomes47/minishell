/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 21:05:43 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:36 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* The atoi() function converts the int value to a converted char pointer */

int	num_size(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dest;
	long	nbr;
	size_t	len;

	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	len = num_size(n);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (0);
	dest[len--] = '\0';
	while (nbr > 0)
	{
		dest[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (len == 0 && dest[1] == '\0')
		dest[0] = '0';
	else if (len == 0 && dest[1] != '\0')
		dest[0] = '-';
	return (dest);
}
