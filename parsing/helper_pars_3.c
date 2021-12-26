/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_pars_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:21:33 by fharing           #+#    #+#             */
/*   Updated: 2021/11/05 15:30:41 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void	ft_init_whitspace_flags(t_wflags *wflags)
{
	wflags->i = 0;
	wflags->x = 0;
	wflags->q = 0;
	wflags->dq = 0;
	wflags->flag = 0;
}

void	ft_remove_whitspaces_strings(char *s)
{
	t_wflags	w;

	ft_init_whitspace_flags(&w);
	while (s[w.i] != 0)
	{
		while (ft_isspace(s[w.i]) == 1 && w.dq % 2 == 0 && w.q % 2 == 0)
		{
			w.flag = 1;
			w.i++;
		}
		if (s[w.i] == '"')
			w.dq++;
		if (s[w.i] == '\'')
			w.q++;
		if (w.flag == 1 && w.x != 0)
		{
			s[w.x] = ' ';
			w.x++;
		}
		s[w.x] = s[w.i];
		w.x++;
		w.i++;
		w.flag = 0;
	}
	s[w.x] = 0;
}

void	ft_remove_whitspaces_strings_end(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	if (i > 0 && ft_isspace(s[i - 1]) == 1)
		s[i - 1] = 0;
}

void	ft_delete_whitespaces(char **s)
{
	while (*s)
	{
		ft_remove_whitspaces_strings(*s);
		s++;
	}
}

void	ft_delete_whitespaces_end(char **s)
{
	while (*s)
	{
		ft_remove_whitspaces_strings_end(*s);
		s++;
	}
}
