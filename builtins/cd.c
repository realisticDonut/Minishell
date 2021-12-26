/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:58:44 by fharing           #+#    #+#             */
/*   Updated: 2021/11/11 15:56:36 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

char	*get_home_path(t_list *env)
{
	t_list	*tmp;
	char	*tmp_pointer;
	char	*re;

	re = NULL;
	tmp = env;
	while (tmp != NULL)
	{
		tmp_pointer = ft_strnstr(tmp->string, "HOME=", 5);
		if (tmp_pointer != NULL)
		{
			re = ft_strdup(tmp_pointer + 5);
			return (re);
		}
		tmp = tmp->next;
	}
	return (re);
}

char	*get_old_pwd(t_list *env)
{
	t_list	*tmp;
	char	*tmp_pointer;
	char	*re;

	re = NULL;
	tmp = env;
	while (tmp != NULL)
	{
		tmp_pointer = ft_strnstr(tmp->string, "OLDPWD=", 7);
		if (tmp_pointer != NULL)
		{
			re = ft_strdup(tmp_pointer + 7);
			return (re);
		}
		tmp = tmp->next;
	}
	return (re);
}

char	*ft_strcat(char *a, char *b)
{
	char	*re;
	int		i;
	int		x;

	i = 0;
	x = 0;
	re = malloc(ft_strlen(a) + ft_strlen(b) + 1);
	while (a[i] != 0)
	{
		re[x] = a[i];
		i++;
		x++;
	}
	i = 0;
	while (b[i] != 0)
	{
		re[x] = b[i];
		x++;
		i++;
	}
	re[x] = 0;
	return (re);
}

int	ft_chdir(const char *path, char *old)
{
	if (chdir(path) == -1)
	{
		perror("cd");
		free (old);
		return (1);
	}
	return (0);
}

int	ft_cd(const char *path, t_list *env)
{
	char	*old;
	int		flag;

	old = getcwd(NULL, 0);
	flag = 0;
	if (path[0] == 0)
	{
		path = get_home_path(env);
		flag = 2;
	}
	else if (path[0] == '-')
	{
		path = get_old_pwd(env);
		flag = 1;
	}
	if (ft_chdir(path, old) == 1)
		return (1);
	ft_set_old_pwd(old, env);
	ft_set_pwd(env);
	if (flag == 1)
		ft_putendl_fd((char *)path, 1);
	if (flag == 2 || flag == 1)
		free ((void *)path);
	free (old);
	return (0);
}
