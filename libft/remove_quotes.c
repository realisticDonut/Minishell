/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:14:32 by fharing           #+#    #+#             */
/*   Updated: 2021/11/08 21:48:43 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*remove_quotes(char *str)
{
	int		i;
	int		count;
	char	*newstr;

	if (!str)
		return (0);
	newstr = ft_calloc(ft_strlen(str), 1);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			i++;
		else
		{
			newstr[count] = str[i];
			i++;
			count++;
		}
	}
	return (newstr);
}
