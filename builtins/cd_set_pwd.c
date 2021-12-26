/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_set_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:34:20 by fharing           #+#    #+#             */
/*   Updated: 2021/11/12 08:40:12 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

void	ft_set_oldpwd_end(char *old, t_list *env, char *new)
{
	new = ft_strcat("OLDPWD=", old);
	ft_lstadd_back(&env, ft_lstnew(new));
	free (new);
}

void	ft_set_old_pwd(char *old, t_list *env)
{
	t_list	*tmp;
	t_list	*start;
	char	*tmp_pointer;
	char	*new;

	start = env;
	new = NULL;
	while (env != NULL)
	{
		tmp = env->next;
		tmp_pointer = ft_strnstr(env->string, "OLDPWD=", 7);
		if (tmp_pointer != NULL)
		{
			free(env->string);
			new = ft_strcat("OLDPWD=", old);
			env->string = ft_strdup(new);
			free (new);
			return ;
		}
		env = tmp;
	}
	env = start;
	if (tmp_pointer == NULL)
		ft_set_oldpwd_end(old, env, new);
}

void	ft_set_pwd_new(char *new, char *path, t_list *env)
{
	new = ft_strcat("PWD=", path);
	ft_lstadd_back(&env, ft_lstnew(new));
	free (new);
	free (path);
}

void	ft_set_pwd(t_list *env)
{
	t_list	*tmp;
	char	*tmp_pointer;
	char	*path;
	char	*new;

	path = getcwd(NULL, 0);
	new = NULL;
	tmp = env;
	while (tmp != NULL)
	{
		tmp_pointer = ft_strnstr(tmp->string, "PWD=", 4);
		if (tmp_pointer != NULL)
		{
			free(tmp->string);
			new = ft_strcat("PWD=", path);
			tmp->string = ft_strdup(new);
			free (new);
			free (path);
			return ;
		}
		tmp = tmp->next;
	}
	if (tmp_pointer == NULL)
		ft_set_pwd_new(new, path, env);
}
