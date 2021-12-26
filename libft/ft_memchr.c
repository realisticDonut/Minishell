/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:49:32 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:49:34 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*schar;

	i = 0;
	schar = (char *)s;
	while (i < (int)n)
	{
		if (schar[i] == (char)c)
		{
			return (&schar[i]);
		}
		i++;
	}
	return (NULL);
}
