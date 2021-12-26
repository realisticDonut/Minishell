/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:50:38 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:51:56 by fharing          ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	size_t	res;
	int		size;
	char	w;

	size = 0;
	i = 0;
	w = 0;
	res = setnum(n);
	while (res / 10 >= 1)
	{
		res = res / 10;
		size++;
	}
	res = setnum(n);
	if (n < 0)
		write(fd, "-", 1);
	while (i < size + 1)
	{
		w = res / fact(size - i + 1) + '0';
		res = res % fact(size - i + 1);
		write(fd, &w, 1);
		i++;
	}
}
