/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:09:49 by agebert           #+#    #+#             */
/*   Updated: 2021/11/11 19:09:50 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

static int	g_heredoc = 0;

int	get_heredoc_pos(char *cmd, t_redirect *redirects)
{
	int	count;

	count = 0;
	if (!cmd || ft_strlen(cmd) < (size_t)(redirects->str_pos))
		return (0);
	if (!cmd[redirects->str_pos])
		return (-1);
	while (cmd[redirects->str_pos] && cmd[redirects->str_pos] != '<')
		redirects->str_pos = redirects->str_pos + 1;
	while (cmd[redirects->str_pos] && cmd[redirects->str_pos] == '<')
	{
		count++;
		redirects->str_pos = redirects->str_pos + 1;
	}
	if (count > 1)
		return (redirects->str_pos);
	else
		return (-1);
}

void	sigfunc_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		g_heredoc = 1;
		write(1, "Hit ENTER to go back to shell!", 31);
		return ;
	}
}

void	heredoc_readline(char *delim, int fd)
{
	char	*str;

	while (1)
	{
		signal(SIGINT, sigfunc_heredoc);
		if (g_heredoc == 1)
		{
			g_heredoc = 0;
			return ;
		}
		str = readline("\x1B[34m>\e[0m ");
		if (str == NULL)
			return ;
		if (ft_strcmp(str, delim))
		{
			free(str);
			break ;
		}
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		if (str)
			free(str);
	}
}

int	heredoc(char *delim, t_files *files)
{
	int		fd;
	int		save_fd;

	save_fd = dup(0);
	dup2(files->fd_save_in, 0);
	fd = open("temp", O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0777);
	if (fd < 0)
	{
		perror("Heredoc");
		return (-1);
	}
	rl_outstream = stderr;
	heredoc_readline(delim, fd);
	dup2(0, save_fd);
	return (fd);
}

void	heredoc_loop(t_commands *commands, t_files *files,
			t_redirect *redirects, int *exit_status)
{
	char	*delim;

	while (get_heredoc_pos(commands->current_cmd_str, redirects) != -1)
	{
		delim = read_red_file_name
			('<', redirects->str_pos, commands->current_cmd_str);
		if (delim[0])
		{
			if (heredoc(delim, files) > -1)
			{
				if (files->file1)
					free(files->file1);
				files->file1 = ft_strdup("temp");
			}
		}
		else
		{
			ft_putendl_fd("syntax error near unexpected token", 2);
			redirects->str_pos_red_in = -1;
			files->in_file_valid = 0;
			*exit_status = 258;
		}
		free(delim);
	}
}
