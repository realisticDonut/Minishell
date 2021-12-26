/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:49:39 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:49:41 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*dstnew;
	char	*srcnew;

	i = 0;
	srcnew = (char *) src;
	dstnew = (char *) dst;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < (int)n)
	{
		dstnew[i] = srcnew[i];
		i++;
	}
	return (dst);
}
