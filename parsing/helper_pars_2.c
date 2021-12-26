/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_pars_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:19:21 by fharing           #+#    #+#             */
/*   Updated: 2021/11/11 16:00:50 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void	ft_skip_all_until_singlequote(char *s, t_flags *flags)
{
	flags->i++;
	while (s[flags->i] != '\'' && s[flags->i] != 0)
		flags->i++;
}

void	ft_skip_all_until_quotes(char *s, t_flags *flags)
{
	flags->i++;
	while (s[flags->i] != '"' && s[flags->i] != 0)
		flags->i++;
}

char	*ft_prepare_string(char *s)
{
	t_flags	f;

	ft_init_flags(&f);
	while (s[f.i] != 0)
	{
		ft_setflags(&f, s[f.i]);
		if (ft_isalpha(s[f.i + 1]) == 1)
			f.redirect = 0;
		if (f.redirect == 0 && f.s_quote == 0 && f.quoation == 0)
			ft_skip_whitspace(s, &f);
		else if (f.redirect == 1 && f.s_quote == 0 && f.quoation == 0)
			ft_skip_whitspace_until_char(s, &f);
		else if (f.redirect == 1 && f.s_quote == 1 && f.quoation == 0)
			ft_skip_all_until_singlequote(s, &f);
		else if (f.redirect == 1 && f.s_quote == 0 && f.quoation == 1)
			ft_skip_all_until_quotes(s, &f);
		else if (f.redirect == 0 && f.s_quote == 0 && f.quoation == 1)
			ft_skip_all_until_quotes(s, &f);
		else if (f.redirect == 0 && f.s_quote == 1 && f.quoation == 0)
			ft_skip_all_until_singlequote(s, &f);
		else
			f.i++;
	}
	return (0);
}

int	ft_check_quotes(char *s)
{
	int	i;
	int	double_quote;
	int	single_quote;

	i = 0;
	double_quote = 0;
	single_quote = 0;
	if (s == NULL)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == '\'' && double_quote % 2 == 0)
			single_quote++;
		if (s[i] == '"' && single_quote % 2 == 0)
			double_quote++;
		i++;
	}
	if (single_quote % 2 == 0 && double_quote % 2 == 0)
		return (1);
	return (0);
}

int	ft_is_space(char *s)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[i] != 0)
	{
		if (ft_isspace(s[i]) == 1)
			x++;
		i++;
	}
	if (x == (int)ft_strlen(s))
		return (1);
	return (0);
}
