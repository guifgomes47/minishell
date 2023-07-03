/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:25:34 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/25 04:16:42 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int get_len(char *str)
{
    int len;

    len = 0;
    while (ft_isalnum(str[len]) || str[len] == '_')
        len++;
    if (!len && str[len] == '?')
        return (1);
    return (len);
}

static void add_escaped(char *src, char *dst, int *i, int *j)
{
    dst[(*j)++] = '\\';
    dst[(*j)++] = src[(*i)++];
}

static char *duplicate_value(char *str)
{
    char *value;
    int len;
    int i;
    int j;

    i = 0;
    j = 0;
    len = ft_strlen(str) * 2;
    value = malloc((len + 1) * sizeof(char));
    while (str[i])
    {
        if (str[i] == '\\' || str[i] == '$' || str[i] == '"' ||
            str[i] == '\'' || str[i] == '>' || str[i] == '<')
            add_escaped(str, value, &i, &j);
        else
            value[j++] = str[i++];
    }
    value[j] = '\0';
    return (value);
}

static char *get_value(char *name, char **envp)
{
	char **env;
	int i;
	int j;
	int c;
	
	i = 0;
	env = envp;
	while (env[i])
	{
		j = 0;
		c = 0;
		while (env[i][j] && env[i][j] != '=' && env[i][j] == name[c])
		{
			c++;
			j++;
		}
		if (env[i][j] == '=' && !name[c])
			return (duplicate_value(&envp[i][j + 1]));
		i++;
	}
	return (NULL);
}

void parser_var(char **input_addr, int *index, t_data *data)
{
    int len;
    char *value;
    char *name;
    char *input;

    len = ft_strlen(*input_addr + *index + 1);
    name = malloc((len + 1) * sizeof(char));
	ft_strncpy(name, *input_addr + *index + 1, len);
	name[len] = '\0';
    if (len == 1 && (*input_addr)[*index + 1] == '?')
		value = ft_strdup("0");
    else if (len)
        value = get_value(name, data->envp);
    else
        value = ft_strdup("$");
    free(name);
    input = malloc((ft_strlen(*input_addr) + ft_strlen(value)) * sizeof(char));
	ft_strncpy(input, *input_addr, *index);
	input[*index] = '\0';
	ft_strcat(input, value);
	ft_strcat(input, *input_addr + *index + 1 + len);
    free(*input_addr);
    *input_addr = input;
    *index += ft_strlen(value) - 1;
    free(value);
}
