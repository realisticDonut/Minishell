/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:57:57 by fharing           #+#    #+#             */
/*   Updated: 2021/11/10 17:15:06 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

void	ft_init_var_getvar(int *i, int *x, int *flag)
{
	*i = 0;
	*x = 0;
	*flag = 0;
}

char	*ft_get_var(char *s)
{
	char	*re;
	int		i;
	int		x;
	int		flag;

	re = malloc(ft_strlen(s) + 1);
	ft_init_var_getvar(&i, &x, &flag);
	while (s[i] != 0)
	{
		if (flag == 1 && s[i] == '$')
			break ;
		if (flag == 1 && ft_isprint(s[i]) == 1 && ft_isspace(s[i]) == 0
			&& s[i] != '"' && s[i] != '\'' && ft_isalnum(s[i]) == 1)
		{
			re[x] = s[i];
			x++;
		}
		else if (flag == 1 && ft_isprint(s[i]) == 1 && ft_isalnum(s[i]) == 0)
			break ;
		if (s[i] == '$')
			flag = 1;
		i++;
	}
	re[x] = 0;
	return (re);
}

char	*ft_get_env_var(char *s, t_list *env)
{
	char	*var;
	char	*tmp_pointer;
	t_list	*tmp;
	int		var_size;

	var = ft_get_var(s);
	if (!var)
		return (0);
	var_size = ft_strlen(var);
	while (env != NULL)
	{
		tmp = env->next;
		tmp_pointer = ft_strnstr(env->string, var, var_size);
		if (tmp_pointer != NULL && *(tmp_pointer + ft_strlen(var)) == '=')
			break ;
		env = tmp;
	}
	free (var);
	return (ft_strdup(tmp_pointer));
}
