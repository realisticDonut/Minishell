/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:49:47 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:49:49 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*bnew;

	i = 0;
	bnew = (char *)b;
	while (i < (int)len)
	{
		bnew[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
