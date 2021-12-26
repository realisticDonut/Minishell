/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:10:05 by agebert           #+#    #+#             */
/*   Updated: 2021/11/12 15:15:24 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./exec_cmds.h"

extern int	g_pid;

int	init_files(t_files *files)
{
	files->fd_save_in = dup(0);
	files->fd_save_out = dup(1);
	files->fd_old = dup(0);
	files->fd_pipe[0] = 0;
	files->fd_pipe[1] = 0;
	files->in_file_valid = 1;
	files->fd_temp_heredoc = -1;
	files->out_file_valid = 1;
	files->file1 = NULL;
	files->file2 = NULL;
	return (1);
}

int	get_input_and_init(char **input, t_list *env,
						t_commands *commands, t_files *files)
{
	char	**env_str;

	env_str = ft_linked_to_string(env);
	commands->cmd_paths = get_cmd_paths(env);
	commands->cmds = copy_str_list(input, env_str);
	if (!commands->cmd_paths || !commands->cmd_paths[0])
	{
		commands->cmd_paths = ft_calloc(10, 1);
	}
	init_files(files);
	g_pid = 0;
	commands->i = 0;
	freestrlist(env_str);
	return (1);
}

void	init_t_redirect(t_redirect *redirects)
{
	redirects->red_count = 0;
	redirects->str_pos_red_in = -1;
	redirects->str_pos_red_out = -1;
	redirects->str_pos = 0;
}

void	init_open_all_out(int *i, int *f_quote)
{
	*i = 0;
	*f_quote = -1;
}
