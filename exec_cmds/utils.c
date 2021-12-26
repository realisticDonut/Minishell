/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:01:25 by fharing           #+#    #+#             */
/*   Updated: 2021/11/11 19:12:06 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./exec_cmds.h"
extern int	g_pid;

int	errno_to_exit(void)
{
	if (errno == 2)
		return (127);
	return (0);
}

char	**get_cmd_paths(t_list *env)
{
	int		i;
	char	**list;
	t_list	*env_temp;

	while (env && env->string)
	{
		env_temp = env->next;
		if (!ft_strncmp(env->string, "PATH=", 5))
			break ;
		env = env_temp;
		if (!env || !env->string)
			return (0);
	}
	list = ft_split(env->string, ':');
	if (!list || !list[0])
		return (0);
	i = 0;
	while (list[0][i + 5])
	{
		list[0][i] = list[0][i + 5];
		i++;
	}
	list[0][i] = 0;
	i = 0;
	return (list);
}

char	**ft_linked_to_string(t_list *env)
{
	char	**re;
	int		i;
	t_list	*tmp;

	re = ft_calloc(ft_lstsize(env) + 1, sizeof(char *));
	i = 0;
	while (env != NULL)
	{
		tmp = env->next;
		re[i] = ft_strdup(env->string);
		env = tmp;
		i++;
	}
	re[i] = 0;
	return (re);
}

void	free_structs(t_commands *commands)
{
	int	i;

	i = 0;
	while (commands->cmd_paths[i])
	{
		free(commands->cmd_paths[i]);
		commands->cmd_paths[i] = NULL;
		i++;
	}
	i = 0;
	while (commands->cmds[i])
	{
		free(commands->cmds[i]);
		commands->cmds[i] = NULL;
		i++;
	}
	free(commands->cmd_paths);
	free(commands->cmds);
	commands->cmd_paths = NULL;
}

char	**copy_str_list(char **old_list, char **env)
{
	int		i;
	int		count_old;
	int		count_env;
	char	**new_list;

	count_old = 0;
	count_env = 0;
	i = 0;
	while (old_list[count_old])
		count_old++;
	while (env[i])
	{
		count_env += ft_strlen(env[i]);
		i++;
	}
	new_list = malloc(count_old * count_env + 1);
	i = 0;
	while (old_list[i])
	{
		new_list[i] = ft_strdup(old_list[i]);
		i++;
	}
	new_list[i] = 0;
	return (new_list);
}
