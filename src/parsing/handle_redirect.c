/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:38:33 by lucperei          #+#    #+#             */
/*   Updated: 2023/06/23 17:08:19 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int get_name_size(char *str)
{
    int index;

    index = 0;
    while (str[index] != ' ' && str[index] != '|' && str[index] != ';' &&
           str[index] != '>' && str[index] != '<' && str[index])
    {
        if (str[index] == '\'')
        {
            while (str[++index] != '\'')
                ;
            index++;
        }
        else if (str[index] == '"')
        {
            while (str[++index] != '"')
            {
                if (str[índex] == '\\')
                    index++;
            }
            index++;
        }
        else
            index++;
    }
    return (index);
}

int fd_is_append(int fd, int append, char *filename)
{
    if (append == 0)
    {
        fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        return (fd);
    }
    else if (append == 1)
    {
        fd = open(filename, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
        return (fd);
    }
    else
    {
        fd = open(filename, O_RDONLY);
        return (fd);
    }
}

void msg_error(t_data *data, t_shell *shell)
{
    printf("Error: wrong permissions\n");
    shell->status = 1;
    data->redirection = 0;
}

void redirect(char *str, int index, char **input, int is_append, int op)
{
    int fd;
    int i;
    char *filename;
    t_shell shell;
    t_data *data;

    i = index;
    if (str[i + 1] == ' ')
        i++;
    filename = get_filename(&(str[i + 1]), &i);
    delete_redirect(input, index, i);
    fd = fd_is_append(fd, is_append, filename);
    free(filename);
    if (fd < 0)
    {
        msg_error(data, shell);
        return;
    }
    dup2(fd, op);
    if (data->fd_output != 1)
        close(data->fd_output);
    data->fd_output = fd;
    parser_redirect(input, data);
}

void handle_redirect(char **input, int index, t_data *data)
{
    char *str;

    str = *input;
    if (str[index] == '>' && str[index + 1] != '>')
        redirect(str, index, 0, 1);
    else if (str[index] == '>' && str[index + 1] == '>')
        redirect(str, index, 1, 1);
    else if (str[index] == '<' && str[index + 1] == '<')
        redirect(str, index, 2, 0);
}