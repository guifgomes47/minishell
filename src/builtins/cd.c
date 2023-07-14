/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:49:53 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/07 02:11:01 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Responsável por mudar o diretório para a variável de ambiente "HOME". Ela verifica 
// se a variável "HOME" está definida no ambiente e, em seguida, utiliza a função chdir() 
// para efetuar a mudança. Após a mudança de diretório, a função handle_pwd() é chamada 
// para atualizar a variável "PWD" do ambiente. Retorna 1 em caso de sucesso e 0 em caso de erro.
int	cd_dir(t_data *data)
{
	if (search_index("HOME=", data) < 0 ||
	chdir((ft_strchr(data->envp[search_index("HOME=", data)], '=') + 1)) == -1)
        return (0);
    handle_pwd(data, NULL);
    return (1);
}

// A função muda para o diretório anterior (utilizando a variável de ambiente "OLDPWD"). 
// Verifica se a variável "OLDPWD" está definida no ambiente e, em seguida, utiliza a função 
// chdir() para realizar a mudança. Após a mudança de diretório, a função handle_pwd() é chamada
// para atualizar a variável "PWD" do ambiente. Retorna 1 em caso de sucesso e 0 em caso de erro.
int cd_sub(t_data *data)
{
    if (search_index("OLDPWD=", data) < 0 ||
    chdir((ft_strchr(data->envp[search_index("OLDPWD=", data)], '=') + 1)) == -1)
        return (0);
    handle_pwd(data, NULL);
    return (1);
}

// Esta função mudar o diretório para o caminho especificado. 
// Ela recebe um argumento de linha de comando contendo o caminho do diretório e utiliza a 
// função chdir() para efetuar a mudança. Após a mudança de diretório, a função handle_pwd() 
// é chamada para atualizar a variável "PWD" do ambiente. Retorna 1 em caso de sucesso e 0 
// em caso de erro.
int	cd_path(char **arg, t_data *data)
{
	if (chdir(arg[1]) == -1)
		return (0);
	handle_pwd(data, arg[1]);
	return (1);
}

// Esta função é a função principal de mudança de diretório. 
// Ela recebe o comando "cd" e o vetor de argumentos (command) e um 
// ponteiro para uma estrutura de dados chamada "t_data". A função verifica os 
// diferentes casos de uso do comando "cd" e chama as funções correspondentes para
// realizar a mudança de diretório. Em cada caso, também são realizadas verificações 
// de erro e mensagens de erro são exibidas, se necessário. A estrutura "t_shell" é 
// usada para armazenar o status da execução do comando.
void ft_cd(char **command, t_data *data)
{
    t_shell shell;

    if (command[1] && command[2])
        return (error_message("Error cd: too many arguments\n", 1));
    else if (!command[1])
    {
        if (!cd_dir(data))
            return (error_message("Error cd: HOME: is undefined\n", 1));
    }
    else if (ft_strcmp(command[1], "-") == 0)
    {
        if (!cd_sub(data))
            return (error_message("Error cd: OLDPWD: is undefined\n", 1));
    }
    else
    {
        if (!cd_path(command, data))
            return (error_message("Error cd: no such file or directory\n", 1));
    }
    shell.status = 0;
}
