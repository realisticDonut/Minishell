/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:51:27 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:52:27 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkchar(char checkc, char const *trimset, size_t lengthset)
{
	size_t	i;

	i = 0;
	while (i < lengthset)
	{
		if (checkc == trimset[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*point;
	size_t	beg;
	size_t	end;
	size_t	lengths1;
	size_t	lengthset;

	beg = 0;
	end = 0;
	if (!s1 || !set)
		return (0);
	lengths1 = ft_strlen(s1);
	lengthset = ft_strlen(set);
	while (checkchar(s1[beg], set, lengthset) && s1[beg] && beg < lengths1)
		beg++;
	while (checkchar(s1[lengths1 - end - 1], set, lengthset)
		&& end < lengths1 - 1)
		end++;
	if (beg >= lengths1)
	{
		return (ft_substr(s1, beg, 1));
	}
	point = ft_substr(s1, beg, lengths1 - end - beg);
	return (point);
}
