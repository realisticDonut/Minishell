/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:38:57 by agebert           #+#    #+#             */
/*   Updated: 2021/11/11 18:05:31 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

void	get_env_str(char *cmd, t_vars *vars, int status, t_list *env)
{
	if (cmd[vars->x + 1] && cmd[vars->x + 1] == '?')
	{
		vars->var_value = ft_itoa(status);
		vars->var_size = 0;
		vars->x += 2;
	}
	else
	{
		vars->var_value = ft_get_env_var(cmd, env);
		vars->var_name = ft_get_var(&cmd[vars->x]);
		vars->var_size = ft_strlen(vars->var_name) + 1;
		vars->x += ft_strlen(vars->var_name) + 1;
	}
}

void	convert_var_to_str(t_vars *vars, int status, t_list *env, char *cmd)
{
	int	i;

	i = 0;
	get_env_str(cmd, vars, status, env);
	while (vars->var_value && i < (int)ft_strlen(vars->var_value)
		&& vars->var_value[i + vars->var_size])
	{
		vars->newcmd[vars->count] = vars->var_value[i + vars->var_size];
		vars->count = vars->count + 1;
		i++;
	}
}

void	append_non_vars(t_vars *vars, char *cmd)
{
	vars->newcmd[vars->count] = cmd[vars->x];
	vars->count = vars->count + 1;
}

char	*convert_vars(char *cmd, t_list *env, int status)
{
	t_vars	*vars;

	vars = malloc(sizeof (*vars));
	if (!env || !cmd || !cmd[0])
		return (0);
	init_t_vars(vars, env);
	while (cmd && cmd[vars->x])
	{
		if (cmd[vars->x] == '\'' && vars->f_quote_double < 0)
			vars->f_quote *= -1;
		if (cmd[vars->x] == '"' && vars->f_quote < 0)
			vars->f_quote_double *= -1;
		if (cmd[vars->x] == '$' && vars->f_quote < 0
			&& ft_isalnum(cmd[vars->x + 1]) == 1)
			convert_var_to_str(vars, status, env, cmd);
		else
		{
			append_non_vars(vars, cmd);
			vars->x++;
		}
		free_vars(vars);
	}
	free(vars);
	return (vars->newcmd);
}
