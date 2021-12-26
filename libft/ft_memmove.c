/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:34:09 by agebert           #+#    #+#             */
/*   Updated: 2021/10/04 11:49:44 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int		i;
	char	*dstnew;
	char	*srcnew;

	i = 0;
	srcnew = (char *) src;
	dstnew = (char *) dst;
	if (dst == 0 && src == 0)
		return (0);
	if (dst < src)
	{
		while (i < (int)n)
		{
			dstnew[i] = srcnew[i];
			i++;
		}
		return (dst);
	}
	i = (int)n - 1;
	while (i >= 0)
	{
		dstnew[i] = srcnew[i];
		i--;
	}
	return (dst);
}
