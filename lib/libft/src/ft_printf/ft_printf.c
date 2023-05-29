/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilhfer <guilhfer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:38:52 by guilhfer          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:55 by guilhfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vfprintf(args, format);
	va_end(args);
	return (len);
}

int	ft_vfprintf(va_list args, const char *format)
{
	int		len;
	int		i;
	t_info	*info;

	i = 0;
	len = 0;
	info = malloc(sizeof(t_info) * 1);
	if (!(info))
		return (-1);
	while (format[i])
	{
		if (format[i] != '%' && format[i])
			len += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			i++;
			info->type = format[i++];
			len += print_type(args, info);
		}
	}
	free(info);
	return (len);
}

int	print_type(va_list args, t_info *info)
{
	int		len;
	char	type;

	len = 0;
	type = info->type;
	if (type == 'c')
		len = print_char(va_arg(args, int));
	if (type == 'd' || type == 'i')
		len = print_digits(va_arg(args, int));
	if (type == 'u')
		len = print_uns_num(va_arg(args, unsigned int));
	if (type == 's')
		len = print_string(va_arg(args, char *));
	if (type == 'x' || type == 'X')
		len = print_hexa(va_arg(args, unsigned int), info);
	if (type == 'p')
		len = print_pointer(va_arg(args, unsigned long int));
	if (type == '%')
		len += write(1, "%", 1);
	return (len);
}
