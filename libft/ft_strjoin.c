/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:51:00 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:52:09 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	lengths1;
	size_t	lengths2;
	char	*point;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	lengths1 = ft_strlen(s1);
	lengths2 = ft_strlen(s2);
	point = malloc(lengths1 + lengths2 + 50);
	if (point == NULL)
		return (NULL);
	while (i < lengths1 + lengths2)
	{
		if (i < lengths1)
			point[i] = s1[i];
		if (i >= lengths1)
			point[i] = s2[i - lengths1];
		i++;
	}
	free((char *)s1);
	point[lengths1 + lengths2] = 0;
	return (point);
}
