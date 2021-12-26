/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_manage_files.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:10:21 by agebert           #+#    #+#             */
/*   Updated: 2021/11/12 15:18:44 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

char	*read_red_file_name(char redirect_char, int str_pos, char *command)
{
	int		count;
	char	rev_red_char;
	char	*filename;
	int		f_quote;
	int		i;

	f_quote = -1;
	count = 0;
	i = 0;
	filename = ft_calloc(ft_strlen(command) + 1, 1);
	rev_red_char = get_rev_redirect_char(redirect_char);
	while (command[i] && i < str_pos)
		i++;
	while (command[i] && command[i] != rev_red_char
		&& command[i] != redirect_char)
	{
		if (command[i] == ' ' && f_quote < 0)
			break ;
		filename[count] = command[i];
		count++;
		i++;
	}
	return (filename);
}

int	check_file_access(char *filename, int *exit_status)
{
	if (access(filename, W_OK) < 0 && access(filename, F_OK) > -1)
	{
		*exit_status = 1;
		ft_free_with_protection(&filename);
		perror(filename);
		return (1);
	}
	return (0);
}

int	open_append_trunc(t_commands *commands, char *filename,
				int i, t_files *files)
{
	int	fd;
	int	ret;

	ret = 0;
	fd = 0;
	if (commands->current_cmd_str[i - 1] == '>')
		fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0777);
	else
		fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
	{
		files->out_file_valid = 0;
		perror(filename);
		ret = 1;
	}
	close(fd);
	return (ret);
}

void	get_file_names(t_files *files, t_commands *commands
		, t_redirect *redirects)
{
	char	*tmp_str;

	files->file1 = read_red_file_name
		('<', redirects->str_pos_red_in, commands->current_cmd_str);
	tmp_str = files->file1;
	files->file1 = ft_remove_quotes(files->file1);
	free(tmp_str);
	files->file2 = read_red_file_name
		('>', redirects->str_pos_red_out, commands->current_cmd_str);
	tmp_str = files->file2;
	files->file2 = ft_remove_quotes(files->file2);
	free(tmp_str);
}
