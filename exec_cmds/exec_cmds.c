/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:01:13 by fharing           #+#    #+#             */
/*   Updated: 2021/11/12 14:38:16 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./exec_cmds.h"

int	g_pid = 0;

void	execute_child(t_files *files, t_commands *commands, t_list *env)
{
	char	**env_str;
	int		i;

	i = 0;
	env_str = ft_linked_to_string(env);
	if (files->in_file_valid)
	{		
		split_cmds_and_paths(commands);
		remove_quotes_from_cmds(commands, &i);
		if (!commands->current_cmd_str
			|| !commands->current_cmd_path
			|| !commands->current_cmd_lst)
			exit(0);
		close(files->fd_pipe[0]);
		execve(commands->current_cmd_path, commands->current_cmd_lst, env_str);
	}
	if (commands->current_cmd_lst[0])
		perror(commands->current_cmd_lst[0]);
	exit(errno_to_exit());
}

void	execute_parent(t_files *files)
{
	dup2(files->fd_pipe[0], files->fd_old);
	close(files->fd_pipe[0]);
	close(files->fd_pipe[1]);
}

void	exec_parent_child(t_commands *commands, t_files *files,
						t_list *env)
{
	if (g_pid == 0)
		execute_child(files, commands, env);
	else
	{
		execute_parent(files);
		commands->i++;
	}
}

void	wait_for_children(int *exit_status)
{
	int	temp_exit_status;

	temp_exit_status = 0;
	if (g_pid != -5)
	{
		while (wait(&temp_exit_status) > 0)
			*exit_status = WEXITSTATUS(temp_exit_status);
	}
}

int	exec_cmds(char **input, t_list *env)
{
	static int	exit_status;
	t_files		files;
	t_commands	commands;

	if (!input || !input[0])
		return (0);
	get_input_and_init(input, env, &commands, &files);
	while (commands.cmds[commands.i])
	{
		convert_vars_and_set_cmds(&commands, env, exit_status, commands.i);
		pipe(files.fd_pipe);
		get_red_str(&commands, &files, commands.i, &exit_status);
		if (check_out_file_valid(&commands, &files, &commands.i))
			continue ;
		check_if_builtin(&files, &commands, env, &exit_status);
		exec_parent_child(&commands, &files, env);
		free(commands.current_cmd_str);
		commands.current_cmd_str = 0;
	}
	wait_for_children(&exit_status);
	free_structs(&commands);
	return (exit_status);
}
