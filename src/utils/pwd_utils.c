/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:05:42 by lucperei          #+#    #+#             */
/*   Updated: 2023/07/05 02:56:25 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Funções que lidam com variáveis de ambiente relacionadas ao diretório atual ("PWD" e "OLDPWD").

// Responsável por lidar com a variável de ambiente "PWD"
void handle_env_pwd(t_data *data)
{
    char *pwd;

	// Obtém o diretório atual usando a função getcwd e armazena o resultado na variável data->dir.
    data->dir = getcwd(NULL, 0);
	// Verifica se a variável "PWD" já está definida em data->envp usando a função search_index
    if (search_index("PWD", data) >= 0)
    {
		// Cria uma string pwd contendo "PWD=" seguido do diretório atual
        pwd = ft_strjoin("PWD=", data->dir);
		// Substitui o valor existente da variável "PWD" pelo novo valor usando a função replace_variable. 
        replace_variable(pwd, data, search_index(pwd, data));
        free(pwd);
    }
    else
    {
        pwd = ft_strjoin("PWD=", data->dir);
		//  Adiciona nova variável pwd ao data->envp usando a função export_envp, 
		// que é responsável por adicionar ou atualizar as variáveis de ambiente. 
        data->envp = export_envp(data->envp, pwd);
        free(pwd);
    }
}

// É semelhante à função anterior, mas lida com a variável de ambiente "OLDPWD" (Old Present Working Directory).
void handle_env_oldpwd(t_data *data)
{
    char *pwd;
    char *oldpwd;

    if (search_index("OLDPWD", data) >= 0)
    {
		// Se estiver definida, cria uma string pwd contendo "PWD=" seguido do diretório atual
        pwd = ft_strjoin("PWD=", data->dir);
		//  Variavel oldpwd contendo "OLDPWD=" seguido do valor de pwd. 
        oldpwd = ft_strjoin("OLD", pwd);
		// Substitui o valor existente da variável "OLDPWD" pelo novo valor usando a função replace_variable. 
        replace_variable(oldpwd, data, search_index("OLDPWD=", data));
        free(oldpwd);
        free(pwd);
    }
    else
	{
		// Verifica se a variável "OLDPWD" já está definida no array data->envp. 
        data->envp = export_envp(data->envp, "OLDPWD");
	}
    free(data->dir);
}

//  Responsável por lidar com a obtenção do diretório atual e chamar as outras duas funções para atualizar as variáveis de ambiente.
int handle_pwd(t_data *data, char *input)
{
    char *pwd;
    char *aux;

// Obtém o diretório atual usando a função getcwd e armazena o resultado na variável 
    aux = getcwd(NULL, 0);
	// verifica se ocorreu algum erro ao obter o diretório atual ou se o usuário digitou o comando "." indicando que deseja exibir o diretório atual 
    if (!aux && input && ft_strcmp(".", input) == 0)
    {
		// Em caso de erro, exibe uma mensagem de erro.
        ft_putstr_fd("Error retrieving current directory\n", 2);
        pwd = data->dir;
        data->dir = ft_strjoin(pwd, "/.");
        free(pwd);
    }
    if (aux)
    {
		// Chama as funções para atualizar as variáveis de ambiente.
        handle_env_pwd(data);
        handle_env_oldpwd(data);
    }
    free(aux);
    return (1);
}
