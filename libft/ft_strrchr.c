/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:51:24 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:52:24 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*spoint;

	spoint = (char *)s;
	i = ft_strlen(s);
	while (spoint[i] != c && i > 0)
	{
		i--;
	}
	if (spoint[i] != c)
		return (NULL);
	return (&spoint[i]);
}
