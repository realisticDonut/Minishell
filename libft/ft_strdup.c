/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:50:56 by fharing           #+#    #+#             */
/*   Updated: 2021/11/01 15:21:04 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*re;

	if (s == NULL)
		return (NULL);
	i = 0;
	re = malloc(ft_strlen(s) + 1);
	while (s[i] != 0)
	{
		re[i] = s[i];
		i++;
	}
	re[i] = 0;
	return (re);
}
