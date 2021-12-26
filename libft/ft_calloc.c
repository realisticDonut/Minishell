/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:48:16 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:48:48 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*point;

	i = 0;
	point = malloc (count * size);
	if (point == NULL)
		return (NULL);
	while (i < count * size)
	{
		point[i] = 0;
		i++;
	}
	return (point);
}
