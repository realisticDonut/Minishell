/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:16:42 by fharing           #+#    #+#             */
/*   Updated: 2021/11/05 15:26:50 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void	ft_init_flags(t_flags *flags)
{
	flags->quoation = 0;
	flags->s_quote = 0;
	flags->redirect = 0;
	flags->i = 0;
}

void	ft_setflags(t_flags *flags, char c)
{
	if (c == '"' && flags->s_quote == 0)
		flags->quoation = 1;
	if (c == '\'')
	{
		flags->quoation = 1;
		flags->s_quote = 0;
		flags->redirect = 0;
	}
	if ((c == '<' || c == '>') && flags->s_quote == 0)
		flags->redirect = 1;
}

void	ft_skip_whitspace(char *s, t_flags *flags)
{
	flags->i++;
	while (ft_isspace(s[flags->i]) == 1 && s[flags->i] != 0)
		flags->i++;
}

void	ft_skip_whitspace_until_char(char *s, t_flags *f)
{
	int	save;
	int	re;

	f->i++;
	save = f->i;
	while (ft_isspace(s[f->i]) == 1 && s[f->i] != 0)
		f->i++;
	if (save == f->i)
		return ;
	while (ft_isspace(s[f->i]) == 0 && ft_isprint(s[f->i]) == 1 && s[f->i] != 0)
	{
		s[save] = s[f->i];
		f->i++;
		save++;
	}
	re = save;
	f->redirect = 0;
	while (s[f->i] != 0)
	{
		s[save] = s[f->i];
		f->i++;
		save++;
	}
	s[save] = 0;
	f->i = re;
}

void	ft_print(char **s)
{
	while (*s)
	{
		ft_putstr_fd(*s, 2);
		write(2, "|\n", 2);
		s++;
	}
}
