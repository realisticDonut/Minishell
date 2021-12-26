/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:08:02 by fharing           #+#    #+#             */
/*   Updated: 2021/11/12 08:49:09 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

char	**ft_echtoctl(void)
{
	char	**re;

	re = malloc(24);
	re[0] = ft_strdup("stty -echoctl");
	re[1] = 0;
	return (re);
}

void	ft_init_shell(int argc, int *out, int *in, t_list	*env)
{
	char	**commands;

	argc = 0;
	*out = dup(1);
	*in = dup(0);
	commands = ft_echtoctl();
	exec_cmds(commands, env);
	freestrlist(commands);
	dup2(*out, 1);
	dup2(*in, 0);
}

char	**ft_start(void)
{
	char	**re;

	re = malloc(66);
	re[0] = ft_strdup
		("say Welcome to the minnishell of f haring and ah gebert");
	re[1] = 0;
	return (re);
}

void	ft_init_shell_say(char **argv, int *out, int *in, t_list	*env)
{
	char	**commands;

	argv = NULL;
	*out = dup(1);
	*in = dup(0);
	commands = ft_start();
	exec_cmds(commands, env);
	freestrlist(commands);
	dup2(*out, 1);
	dup2(*in, 0);
}
