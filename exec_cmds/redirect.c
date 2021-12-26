/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 09:28:28 by fharing           #+#    #+#             */
/*   Updated: 2021/11/12 15:51:31 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

int	redirect_in(t_files *files, int fd_file_in,
				t_redirect *redirects, int *exit_status)
{
	if (redirects->str_pos_red_in > -1)
	{
		fd_file_in = open(files->file1, R_OK);
		if (fd_file_in < 0)
		{
			files->in_file_valid = 0;
			*exit_status = 1;
			perror(files->file1);
			return (-1);
		}
		dup2(fd_file_in, 0);
	}
	else
		dup2(files->fd_old, 0);
	return (1);
}

int	redirect_out(t_files *files, int fd_file_out
					, t_redirect *redirects, int *exit_status)
{
	if (redirects->str_pos_red_out > -1)
	{
		if (redirects->red_count < 2)
			fd_file_out = open(files->file2, O_RDWR | O_CREAT | O_TRUNC, 0777);
		else
			fd_file_out = open(files->file2, O_RDWR | O_CREAT | O_APPEND, 0777);
		if (fd_file_out < 0)
		{
			perror(files->file2);
			*exit_status = 1;
			return (-1);
		}
		dup2(fd_file_out, 1);
	}
	return (1);
}

int	redirect(t_files *files, t_redirect *redirects, int *exit_status)
{
	int	fd_file_in;
	int	fd_file_out;

	fd_file_in = 0;
	fd_file_out = 0;
	if (files->out_file_valid)
	{
		if (redirect_out(files, fd_file_out, redirects, exit_status) < 0
			|| redirect_in(files, fd_file_in, redirects, exit_status) < 0)
			return (-1);
	}
	return (0);
}

char	*remove_redirects(char *command)
{
	int		i;
	int		count;
	char	*new_command;
	int		f_quote_s;
	int		f_quote_d;

	init_remove_redirects(&count, &i, &f_quote_d, &f_quote_s);
	new_command = ft_calloc(ft_strlen(command) + 1, 1);
	while (command[i])
	{
		check_quotes(&f_quote_d, &f_quote_d, &command[i]);
		if ((command[i] == '<' || command[i] == '>')
			&& (f_quote_d < 0 && f_quote_s < 0))
		{
			while (command[i] && command[i] != ' '
				&& (command[i] != '\'' || f_quote_d > 0)
				&& (command[i] != '"' || f_quote_s > 0))
				i++;
		}
		new_command[count] = command[i];
		count++;
		i++;
	}
	return (new_command);
}

char	*set_redirects(t_commands *commands, t_files *files,
				int cmd_count, int *exit_status)
{
	t_redirect	redirects;

	init_t_redirect(&redirects);
	redirects.str_pos_red_in
		= get_last_red_pos(commands->current_cmd_str, '<') + 1;
	redirects.str_pos_red_out
		= get_last_red_pos(commands->current_cmd_str, '>') + 1;
	redirects.red_count = count_chain_chars
		(commands->current_cmd_str, redirects.str_pos_red_out);
	open_all_out(files, commands, exit_status, &redirects);
	get_file_names(files, commands, &redirects);
	heredoc_loop(commands, files, &redirects, exit_status);
	if (commands->cmds[cmd_count + 1])
		dup2(files->fd_pipe[1], 1);
	else
		dup2(files->fd_save_out, 1);
	if (files->out_file_valid == 1 && redirects.red_count < 3)
		redirect(files, &redirects, exit_status);
	ft_free_with_protection(&files->file1);
	ft_free_with_protection(&files->file2);
	return (remove_redirects(commands->current_cmd_str));
}
