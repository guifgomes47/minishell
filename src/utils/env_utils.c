/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 03:47:57 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/08 18:30:02 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Calcula o tamanho da env
int env_len(char **env)
{
	int index;
	
	index = 0;
	while (env[index])
		index++;
	return (++index);
}
