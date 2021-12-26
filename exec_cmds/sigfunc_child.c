/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigfunc_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:37:26 by agebert           #+#    #+#             */
/*   Updated: 2021/11/12 14:37:27 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"
extern int	g_pid;

void	sigfunc_child(int sig)
{
	if (sig == SIGINT || sig == SIGQUIT)
	{
		kill(g_pid, sig);
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
}
