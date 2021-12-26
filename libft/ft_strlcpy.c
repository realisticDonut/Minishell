/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:51:09 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:52:14 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	size_t			lengthsrc;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	lengthsrc = ft_strlen(src);
	if (dstsize == 0)
		return (lengthsrc);
	while (i < dstsize - 1 && src[i] != 0)
	{
		dst [i] = src[i];
		i++;
	}
	dst [i] = '\0';
	return (lengthsrc);
}
