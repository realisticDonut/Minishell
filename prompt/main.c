/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:31:25 by fharing           #+#    #+#             */
/*   Updated: 2021/11/12 15:26:08 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

int	main(int argc, char **argv, char **env)
{
	char	*s;
	t_list	*history;
	t_list	*env_s;
	int		out;
	int		in;

	env_s = ft_create_struct_env(env);
	ft_init_shell(argc, &out, &in, env_s);
	ft_init_shell_say(argv, &out, &in, env_s);
	while (1)
	{
		signal(SIGINT, sigfunc);
		signal(SIGQUIT, SIG_IGN);
		s = readline("\x1B[34mminishell@KINGZZZZ:\e[0m ");
		if (s && *s && ft_isspace(s[0]) == 0)
		{
			ft_lstadd_back(&history, ft_lstnew(s));
			add_history(s);
		}
		ft_parse(s, history, env_s);
		dup2(out, 1);
		dup2(in, 0);
		free (s);
	}
	ft_free_structs_history(history, env_s);
}
