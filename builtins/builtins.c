/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:04:29 by fharing           #+#    #+#             */
/*   Updated: 2021/11/12 10:48:43 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

char	*get_cmd_args(char *cmd)
{
	int		i;
	int		count;
	char	*args;

	args = ft_calloc(ft_strlen(cmd) + 1, sizeof(char));
	count = 0;
	i = 0;
	while (cmd && cmd[i] && cmd[i] != ' ')
		i++;
	if (cmd[i] == ' ')
		i++;
	while (cmd && cmd[i])
	{
		args[count] = cmd[i];
		count++;
		i++;
	}
	return (args);
}

char	*get_cmd_name(char *cmd)
{
	char	*cmd_name;
	char	*cmd_name_new;
	int		count;

	count = 0;
	cmd_name = ft_calloc(ft_strlen(cmd) + 1, 1);
	while (cmd[count] && cmd[count] != ' ')
	{
		if (cmd[0] == '$')
		{
			cmd_name[0] = '$';
			break ;
		}
		cmd_name[count] = cmd[count];
		count++;
	}
	cmd_name_new = remove_quotes(cmd_name);
	free(cmd_name);
	cmd_name = NULL;
	return (cmd_name_new);
}

int	call_builtin_funcs(char *cmd_name, int *exit_status,
				char *cmd_args, t_list *env)
{
	int		ret;

	ret = 1;
	if (ft_strcmp_conv_capital("env", cmd_name))
		ft_env(env);
	else if (ft_strcmp_conv_capital("cd", cmd_name))
		*exit_status = ft_cd(cmd_args, env);
	else if (ft_strcmp_conv_capital("exit", cmd_name))
		*exit_status = ft_exit(cmd_args, exit_status);
	else if (ft_strcmp_conv_capital("export", cmd_name))
		*exit_status = ft_export(cmd_args, env);
	else if (ft_strcmp_conv_capital("pwd", cmd_name))
		ft_pwd();
	else if (ft_strcmp_conv_capital("unset", cmd_name))
		*exit_status = ft_unset(cmd_args, env);
	else
		ret = 0;
	return (ret);
}

/*
*call_builtins
*Checks if command is a built-in command
*If built-in: Execute and Return 1
*If not built-in: Return 0
*/
int	call_builtins(char *cmd, t_list *env, int *exit_status)
{
	char	*cmd_name;
	char	*cmd_args_temp;
	char	*cmd_args;
	int		ret;

	ret = 1;
	if (!cmd)
		return (-1);
	cmd_name = get_cmd_name(cmd);
	cmd_args_temp = get_cmd_args(cmd);
	cmd_args = ft_remove_quotes(cmd_args_temp);
	free(cmd_args_temp);
	if (ft_strcmp_conv_capital("echo", cmd_name))
	{
		*exit_status = ft_echo(cmd_args_temp);
		ret = 1;
	}
	else
		ret = call_builtin_funcs(cmd_name, exit_status, cmd_args, env);
	free(cmd_name);
	free(cmd_args);
	return (ret);
}
