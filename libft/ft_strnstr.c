/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:51:20 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:52:22 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	length;
	int	counthay;

	i = 0;
	counthay = 0;
	length = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)&haystack[0]);
	while (haystack[counthay] != '\0' && counthay < (int)len)
	{
		while (haystack[counthay + i] != '\0'
			&& haystack[counthay + i] == needle[i] && (i + counthay < (int)len))
		{
			i++;
			if (i == length)
				return ((char *)&haystack[counthay]);
		}
		counthay++;
		i = 0;
	}
	return (NULL);
}
