/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:49:13 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:49:21 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fact(int power)
{
	int	i;
	int	ergebnis;

	i = 0;
	ergebnis = 1;
	while (i < power - 1)
	{
		ergebnis = ergebnis * 10;
		i++;
	}
	return (ergebnis);
}

static	size_t	setnum(int n)
{
	if (n < 0)
	{
		return ((size_t)n * -1);
	}
	return (n);
}

static char	*writeitoa(size_t size, int n, size_t i)
{
	size_t	nnew;
	char	*point;

	nnew = setnum(n);
	while (nnew / 10 >= 1)
	{
		nnew = nnew / 10;
		size++;
	}
	if (n < 0)
		size = size + 1;
	point = malloc(size + 1);
	if (point == NULL)
		return (NULL);
	if (n < 0)
		point[0] = '-';
	nnew = setnum(n);
	while (i < size)
	{
		point[i] = (nnew / fact(size - i)) + '0';
		nnew = nnew % fact(size - i);
		i++;
	}
	point[size] = '\0';
	return (point);
}

char	*ft_itoa(int n)
{
	size_t	size;
	size_t	i;

	size = 1;
	i = 0;
	if (n < 0)
		i = 1;
	return (writeitoa(size, n, i));
}
