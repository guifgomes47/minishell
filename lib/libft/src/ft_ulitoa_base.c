/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:40:14 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:36 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	uns_base_len(unsigned long int n, int base_len)
{
	unsigned long int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_ulitoa_base(unsigned long int n, char *base)
{
	char	*dest;
	int		b_len;
	int		len;

	b_len = ft_strlen(base);
	len = uns_base_len(n, b_len);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	dest[len--] = '\0';
	while (n > 0)
	{
		dest[len--] = base[n % b_len];
		n /= b_len;
	}
	if (len == 0 && dest[1] == '\0')
		dest[0] = '0';
	return (dest);
}
