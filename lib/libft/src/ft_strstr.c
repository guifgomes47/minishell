/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 05:46:09 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/25 05:51:14 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char *ft_strstr(const char *stack, const char *c)
{
    size_t len;

    len = ft_strlen(c);
    if (!(*c))
        return ((char *)stack);
    while (*stack)
    {
        if (ft_strncmp(stack, c, len) != 0)
            stack++;
        else
            return ((char *)stack);
    }
    return (NULL);
}
