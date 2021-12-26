/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_numlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:52:40 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:52:44 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates and initializes an array of numbers with 0
** lstcount represents the amount of integers
** returns the pointer to the first element of the array
*/
int	*init_numlist(int lstcount)
{
	int	i;
	int	*numlist;

	numlist = (int *)malloc(lstcount * sizeof(int));
	i = 0;
	while (i < lstcount)
	{
		numlist[i] = 0;
		i++;
	}
	return (numlist);
}
