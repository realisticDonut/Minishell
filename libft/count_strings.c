/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:47:52 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 12:51:09 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countstrings(char **strings, char delim)
{
	int		i;
	int		j;
	int		count;
	char	**tempstrings;

	count = 0;
	i = 0;
	j = 0;
	while (strings[i])
	{
		tempstrings = ft_split(strings[i], delim);
		while (tempstrings[j])
		{
			free(tempstrings[j]);
			j++;
			count++;
		}
		free(tempstrings);
		j = 0;
		i++;
	}
	i = 0;
	return (count);
}
