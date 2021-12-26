/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:49:27 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:49:29 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	char			*dstnew;
	char			*srcnew;
	unsigned char	newc;

	i = 0;
	newc = (unsigned char)c;
	srcnew = (char *) src;
	dstnew = (char *) dst;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < (int)n)
	{
		dstnew[i] = srcnew[i];
		if ((unsigned char)srcnew[i] == newc)
		{
			return (&dstnew[i + 1]);
			break ;
		}
		i++;
	}
	return (NULL);
}
