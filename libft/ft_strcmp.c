/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:57:38 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 17:13:45 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s, char *a)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	if (ft_strlen(s) != ft_strlen(a))
		return (0);
	while (s[i] != 0 && a[i] != 0)
	{
		if (s[i] != a[i])
			return (0);
		i++;
	}
	return (1);
}
