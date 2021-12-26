/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:51:04 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:52:11 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	size_t			length;
	size_t			lengthsrc;

	i = 0;
	length = ft_strlen(dst);
	lengthsrc = ft_strlen(src);
	if (dstsize == 0)
	{
		return (lengthsrc);
	}
	if (lengthsrc == 0)
	{
		return (length);
	}
	while (i + length < dstsize - 1 && src[i] != '\0')
	{
		dst[i + length] = src[i];
		i++;
	}
	if (length >= dstsize)
		return (lengthsrc + dstsize);
	dst [i + length] = '\0';
	return (lengthsrc + length);
}
