/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:07:38 by fharing           #+#    #+#             */
/*   Updated: 2021/11/09 10:39:21 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

void	numeric_args_only(char *cmd_args)
{
	write(2, "exit: ", 6);
	write(2, cmd_args, ft_strlen(cmd_args));
	write(2, ": numeric argument required\n", 28);
	exit(255);
}

int	too_many_args(int *exit_status)
{
	*exit_status = 1;
	ft_putendl_fd("exit: too many arguments", 2);
	return (-1);
}

int	wordcount(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			if (str[i])
				count++;
		}
		i++;
	}
	return (count);
}

int	ft_exit(char *cmd_args, int *exit_status)
{
	int	i;

	i = 0;
	if (!cmd_args || !cmd_args[0])
		exit(0);
	while (cmd_args[i])
	{
		if (wordcount(cmd_args) > 1)
			return (too_many_args(exit_status));
		else if ((cmd_args[i] < '0' || cmd_args[i] > '9') && cmd_args[i] != ' '
			&& cmd_args[i] != '-' && cmd_args[i] != '+')
			numeric_args_only(cmd_args);
		i++;
	}
	exit(ft_atoi(cmd_args));
}
