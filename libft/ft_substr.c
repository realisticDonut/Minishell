/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:51:31 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:52:29 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*point;

	if (s == NULL)
		return (0);
	i = start;
	point = malloc (len + 1);
	if (point == NULL)
		return (NULL);
	if (s[0] == 0 || start > ft_strlen(s))
	{
		point[0] = 0;
		return (point);
	}
	while (i - start < len)
	{
		point[i - start] = s[i];
		i++;
	}
	point[i - start] = 0;
	return (point);
}
