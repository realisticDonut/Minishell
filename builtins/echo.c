/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:03:04 by fharing           #+#    #+#             */
/*   Updated: 2021/11/12 10:50:51 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

int	ft_echo_flag(char *s)
{
	int	i;

	i = 1;
	if (s[0] == '-' && s[1] == 'n')
	{
		while (s[i] != 0)
		{
			if (s[i] == '-')
				i++;
			while (s[i] == 'n')
				i++;
			if (s[i] != ' ')
				return (0);
			if (!(s[i] == ' ' && s[i + 1] == '-'))
				return (1);
			i++;
		}
	}
	return (0);
}

int	ft_offset(char *s)
{
	int	i;

	i = 2;
	while (s[i] == 'n' || s[i] == ' ' || s[i] == '-')
	{
		i++;
	}
	if (s[i] == 0)
		return (i);
	if (s[i - 1] == '-' || s[i - 1] == 'n')
		i--;
	return (i);
}

void	ft_init_vars_echo(t_var_echo *var)
{
	var->i = 0;
	var->quotes = 0;
	var->end = 0;
	var->x = 0;
}

int	ft_quotes_in_quote(char *s)
{
	t_var_echo	var;

	ft_init_vars_echo(&var);
	if (s[var.i] == '\'' || s[var.i] == '"')
	{
		var.c = s[var.i];
		var.i++;
		var.x = var.i;
		while (s[var.x] != 0 && s[var.x] != var.c)
			var.x++;
		var.end = var.x;
		if (var.end == (int)ft_strlen(s))
			return (0);
	}
	while (s[var.i] != 0 && var.i < var.x)
	{
		if (s[var.i] == '\'' || s[var.i] == '"')
			var.quotes++;
		var.i++;
	}
	if (var.quotes > 0 && var.quotes % 2 == 0)
		return (1);
	return (0);
}

int	ft_echo(char *in)
{
	int		i;
	char	*echo;

	i = 0;
	echo = ft_remove_quotes(in);
	if (echo == NULL)
		return (0);
	if (ft_echo_flag(echo) == 1 && ft_quotes_in_quote(in) == 0)
		i = ft_offset(echo);
	while (echo[i] != 0)
	{
		write(1, &echo[i], 1);
		i++;
	}
	if (ft_echo_flag(echo) == 0 || ft_quotes_in_quote(in) == 1)
		printf("\n");
	free(echo);
	return (0);
}
