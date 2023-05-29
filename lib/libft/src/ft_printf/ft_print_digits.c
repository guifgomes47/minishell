/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:50:22 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:52 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	print_digits(int d)
{
	int		i;
	char	*digits;

	i = 0;
	digits = ft_itoa(d);
	i += write(1, digits, ft_strlen(digits));
	free(digits);
	return (i);
}

int	print_uns_num(unsigned int d)
{
	int		i;
	char	*digits;

	i = 0;
	digits = (ft_ulitoa_base(d, DIGITS));
	i += write(1, digits, ft_strlen(digits));
	free(digits);
	return (i);
}

int	print_hexa(unsigned int d, t_info *info)
{
	int		i;
	char	*hexa;

	i = 0;
	if (info->type == 'x')
		hexa = (ft_ulitoa_base(d, HEXALOW));
	if (info->type == 'X')
		hexa = (ft_ulitoa_base(d, HEXAUPP));
	i += write(1, hexa, ft_strlen(hexa));
	free(hexa);
	return (i);
}

int	print_pointer(unsigned long int d)
{
	int		i;
	char	*pointer;

	i = 0;
	if (!d)
	{
		i += write(1, "(nil)", 5);
		return (i);
	}
	else
	{
		i += write(1, "0x", 2);
		pointer = ft_ulitoa_base(d, HEXALOW);
	}
	i += write(1, pointer, ft_strlen(pointer));
	free(pointer);
	return (i);
}
