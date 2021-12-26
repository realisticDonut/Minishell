/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:19:12 by agebert           #+#    #+#             */
/*   Updated: 2021/11/12 13:03:56 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"

int	get_last_red_pos(char *str, char c)
{
	int	count;
	int	pos_found;
	int	f_quote;

	f_quote = -1;
	pos_found = -2;
	count = 0;
	if (!str)
		return (0);
	while (str[count])
	{
		if (str[count] == '"' || str[count] == '\'')
			f_quote *= -1;
		if (str[count] == c && c == '<' && f_quote < 0
			&& str[count + 1] != '<')
			pos_found = count;
		if (str[count] == c && c == '>' && f_quote < 0
			&& str[count + 1] != '>')
			pos_found = count;
		count++;
	}
	return (pos_found);
}

int	count_chain_chars(char *str, int str_pos)
{
	int		charcount;
	char	c;
	int		i;

	i = 0;
	str_pos -= 1;
	charcount = 0;
	if (!str)
		return (0);
	while (str[i] && i < str_pos)
		i++;
	c = str[i];
	while (str[i] && str[i] == c)
	{
		charcount++;
		i--;
	}
	return (charcount);
}

char	get_rev_redirect_char(char redirect_char)
{
	if (redirect_char == '<')
		return ('>');
	else
		return ('<');
}

void	check_quotes(int *f_quote_d, int *f_quote_s, char *command)
{
	if (*f_quote_s < 0 && command[0] == '"')
		*f_quote_d *= -1;
	if (*f_quote_d < 0 && command[0] == '\'')
		*f_quote_d *= -1;
}

void	init_remove_redirects(int *count, int *i,
			int *f_quote_d, int *f_quote_s)
{
	*count = 0;
	*i = 0;
	*f_quote_d = -1;
	*f_quote_s = -1;
}
