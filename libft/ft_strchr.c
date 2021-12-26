/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:50:52 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:52:02 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	searchChar;
	int		i;

	i = 0;
	searchChar = c;
	while (s[i] != searchChar && s[i] != '\0')
	{
		i++;
	}
	if (searchChar != '\0' && s[i] != searchChar)
		return (NULL);
	return ((char *) &s[i]);
}
