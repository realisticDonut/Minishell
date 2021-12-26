/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:01:18 by agebert           #+#    #+#             */
/*   Updated: 2021/11/12 12:49:28 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./exec_cmds.h"

extern int	g_pid;

void	check_if_builtin(t_files *files, t_commands *commands,
			 t_list *env, int *exit_status)
{
	if (!call_builtins(commands->current_cmd_str, env, exit_status)
		&& files->in_file_valid)
	{
		signal(SIGINT, sigfunc_child);
		signal(SIGQUIT, sigfunc_child);
		g_pid = fork();
	}
	else
		g_pid = -5;
}

int	check_out_file_valid(t_commands *commands, t_files *files, int *i)
{
	if (!files->out_file_valid)
	{
		*i = *i + 1;
		free(commands->current_cmd_str);
		commands->current_cmd_str = 0;
		return (1);
	}
	return (0);
}

char	*check_command(char *command, t_commands *commands)
{
	char	*full_path;
	int		i;

	i = 0;
	if (!command)
		return (0);
	while (commands->cmd_paths && commands->cmd_paths[i])
	{
		full_path = ft_strjoin(ft_strdup(commands->cmd_paths[i]), "/");
		full_path = ft_strjoin(full_path, command);
		if (access(full_path, F_OK) > -1)
			return (full_path);
		free(full_path);
		i++;
	}
	return (command);
}
