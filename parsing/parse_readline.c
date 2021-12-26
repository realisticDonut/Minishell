/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_readline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:10:13 by fharing           #+#    #+#             */
/*   Updated: 2021/11/11 13:28:18 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void	ft_parse(char *s, t_list *history, t_list *env)
{
	char	**commands;

	if (s == NULL)
	{
		free (s);
		ft_free_structs_history(history, env);
		exit(0);
	}
	if (ft_check_quotes(s) == 0)
		return ;
	if (ft_is_space(s) == 1)
		return ;
	if (ft_strcmp(s, "history") == 1)
		ft_lstprint(history);
	else
	{
		ft_prepare_string(s);
		commands = ft_split_quote(s, '|');
		ft_delete_whitespaces(commands);
		ft_delete_whitespaces_end(commands);
		exec_cmds(commands, env);
		freestrlist(commands);
	}
}
