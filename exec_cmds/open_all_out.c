/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_all_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:19:26 by agebert           #+#    #+#             */
/*   Updated: 2021/11/12 15:38:03 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

int	check_open(int i, t_commands *commands, t_files *files, int *exit_status)
{
	char	*filename;

	filename
		=read_red_file_name('>', i, commands->current_cmd_str + 1);
	if (filename[0])
	{
		if (check_file_access(filename, exit_status))
			return (1);
		if (open_append_trunc(commands, filename, i, files))
			*exit_status = 1;
	}
	ft_free_with_protection(&filename);
	return (0);
}

void	open_all_out(t_files *files, t_commands *commands,
			int *exit_status, t_redirect *redirects)
{
	int		i;
	int		f_quote;

	if (redirects->red_count > 2)
	{
		write(2, "syntax error near unexpected token\n", 36);
		*exit_status = 258;
		files->out_file_valid = 0;
		return ;
	}
	init_open_all_out(&i, &f_quote);
	if (!commands->current_cmd_str || !commands->current_cmd_str[i])
		return ;
	while (commands->current_cmd_str && commands->current_cmd_str[i])
	{
		if (commands->current_cmd_str[i] == '"'
			|| commands->current_cmd_str[i] == '\'')
			f_quote *= -1;
		if (commands->current_cmd_str[i] == '>' && f_quote < 0)
		{
			if (check_open(i, commands, files, exit_status))
				break ;
		}
		i++;
	}
}
