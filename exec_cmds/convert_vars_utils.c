/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_vars_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:38:54 by agebert           #+#    #+#             */
/*   Updated: 2021/11/11 18:06:19 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

int	count_chars_env_list(t_list *env)
{
	int	count;

	count = 0;
	while (env && env->next && env->string)
	{
		count += ft_strlen(env->string);
		env = env->next;
	}
	return (count);
}

void	init_t_vars(t_vars *vars, t_list *env)
{
	vars->var_size = 0;
	vars->newcmd = ft_calloc(count_chars_env_list(env) + 1, 1);
	vars->var_name = NULL;
	vars->var_value = NULL;
	vars->f_quote = -1;
	vars->f_quote_double = -1;
	vars->count = 0;
	vars->x = 0;
}

void	free_vars(t_vars *vars)
{
	if (vars->var_name)
	{
		free(vars->var_name);
		vars->var_name = NULL;
	}
	if (vars->var_value)
	{
		free(vars->var_value);
		vars->var_value = NULL;
	}
}
