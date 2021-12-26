/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:08:11 by fharing           #+#    #+#             */
/*   Updated: 2021/10/04 11:43:31 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		printf("%d: %s\n", i, lst->string);
		lst = lst->next;
		i++;
	}
}
