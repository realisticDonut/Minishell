/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_format_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:01:22 by agebert           #+#    #+#             */
/*   Updated: 2021/11/12 12:47:07 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./exec_cmds.h"

void	remove_quotes_from_cmds(t_commands *commands, int *i)
{
	char	*temp_str;

	while (commands->current_cmd_lst && commands->current_cmd_lst[*i])
	{
		temp_str = commands->current_cmd_lst[*i];
		commands->current_cmd_lst[*i]
			= ft_remove_quotes(commands->current_cmd_lst[*i]);
		free(temp_str);
		temp_str = NULL;
		*i = *i + 1;
	}
}

void	convert_vars_and_set_cmds(t_commands *commands, t_list *env,
								 int exit_status, int i)
{
	char	*tempstr;

	tempstr = convert_vars(commands->cmds[i], env, exit_status);
	free (commands->cmds[i]);
	commands->cmds[i] = tempstr;
}

void	split_cmds_and_paths(t_commands *commands)
{
	commands->current_cmd_path = check_command(
			ft_remove_quotes
			(ft_split_quote(commands->current_cmd_str, ' ')[0]), commands);
	commands->current_cmd_lst = ft_split_quote(
			commands->current_cmd_str, ' ');
}

/*
*sets redirections
*sets command string without redirection statements
*/
void	get_red_str(t_commands *commands, t_files *files,
				 int cmd_count, int *exit_status)
{
	commands->current_cmd_str = commands->cmds[cmd_count];
	commands->current_cmd_str
		= set_redirects(commands, files, cmd_count, exit_status);
}
