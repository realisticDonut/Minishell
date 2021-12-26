/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:09:13 by fharing           #+#    #+#             */
/*   Updated: 2021/11/12 13:41:07 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

char	*ft_get_first_word(char *s)
{
	char	*re;
	int		i;
	int		x;
	int		flag;

	re = malloc(sizeof(ft_strlen(s)));
	i = 0;
	x = 0;
	flag = 0;
	if (s[i] != 0)
	{
		while (ft_isspace(s[i]) == 1)
			i++;
		while (ft_isprint(s[i]) == 1 && ft_isspace(s[i]) == 0 && s[i] != 0)
		{
			re[x] = s[i];
			x++;
			i++;
		}
	}
	re[x] = 0;
	return (re);
}

int	ft_loop_unset(char *var, t_list *env)
{
	char	*tmp_pointer;
	t_list	*tmp;
	t_list	*before;

	while (env != NULL)
	{
		tmp = env->next;
		tmp_pointer = ft_strnstr(env->string, var, ft_strlen(var));
		if (tmp_pointer != NULL)
		{
			before->next = tmp;
			free(env->string);
			free(env);
			free (var);
			return (0);
		}
		before = env;
		env = tmp;
	}
	return (1);
}

int	ft_unset(char *s, t_list *env)
{
	char	*var;

	if (s[0] == 0)
		return (1);
	if (ft_isdigit(s[0]) == 1 && s[0] != 0)
	{
		ft_print_error();
		return (1);
	}
	else if (ft_isalnum(s[0]) == 0 && s[0] != 0)
	{
		ft_print_error();
		return (258);
	}
	var = ft_get_first_word(s);
	if (ft_loop_unset(var, env) == 1)
		free (var);
	return (0);
}
