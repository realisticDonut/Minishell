/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:07:00 by fharing           #+#    #+#             */
/*   Updated: 2021/11/08 15:32:11 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void	ft_free_structs_history(t_list *history, t_list *env_s)
{
	if (history)
		ft_free_stack(history);
	ft_free_stack(env_s);
	rl_clear_history();
}

void	ft_print_stack(t_list *list)
{
	t_list	*tmp;

	while (list != NULL)
	{
		tmp = list->next;
		printf("%s\n", list->string);
		list = tmp;
	}
}

int	ft_free_stack(t_list *list)
{
	t_list	*tmp;

	tmp = list->next;
	while (tmp != NULL)
	{
		free(tmp->string);
		list = tmp;
		free (tmp);
		tmp = list->next;
	}
	return (0);
}

t_list	*ft_create_struct_env(char **env)
{
	t_list	*re;
	int		i;

	i = 1;
	if (!env)
		return (0);
	re = ft_lstnew(env[0]);
	while (env[i])
	{
		ft_lstadd_back(&re, ft_lstnew(env[i]));
		i++;
	}
	return (re);
}

void	sigfunc(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
}
