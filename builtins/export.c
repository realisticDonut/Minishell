/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:21:12 by fharing           #+#    #+#             */
/*   Updated: 2021/11/12 13:37:15 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

char	*ft_get_variable(char *s)
{
	char	*re;
	int		i;
	int		x;

	re = malloc(ft_strlen(s) + 1);
	i = 0;
	x = 0;
	if (s[i] != 0)
	{
		while (ft_isspace(s[i]) == 1)
			i++;
		while (ft_isprint(s[i]) == 1 && ft_isspace(s[i]) == 0
			&& s[i] != 0 && s[i] != '=')
		{
			re[x] = s[i];
			x++;
			i++;
		}
	}
	re[x] = 0;
	return (re);
}

int	ft_print_error(void)
{
	ft_putendl_fd("not a valid identifier/syntax error", 1);
	return (0);
}

int	ft_validate(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0 && ft_isalnum(s[i]) == 1)
		i++;
	if (s[i] == '=')
		return (1);
	return (0);
}

int	ft_loop_export(char *var, char *s, t_list *env)
{
	t_list	*tmp;
	t_list	*start;
	char	*tmp_pointer;

	start = env;
	while (env != NULL)
	{
		tmp = env->next;
		tmp_pointer = ft_strnstr(env->string, var, ft_strlen(var));
		if (tmp_pointer != NULL && tmp_pointer[ft_strlen(var)] == '=')
		{
			free(env->string);
			env->string = ft_strdup(s);
			free(var);
			return (0);
		}
		env = tmp;
	}
	env = start;
	return (1);
}

int	ft_export(char *s, t_list *env)
{
	char	*var;

	if (s[0] == 0)
	{
		ft_env(env);
		return (0);
	}
	if (ft_isdigit(s[0]) == 1)
	{
		ft_print_error();
		return (1);
	}
	if (ft_isalnum(s[0]) == 0 || ft_validate(s) == 0)
	{
		ft_print_error();
		return (258);
	}
	var = ft_get_variable(s);
	if (ft_loop_export(var, s, env) == 1)
	{
		ft_lstadd_back(&env, ft_lstnew(s));
		free(var);
	}
	return (0);
}
