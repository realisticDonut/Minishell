/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:59:37 by fharing           #+#    #+#             */
/*   Updated: 2021/11/09 10:39:28 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

int	ft_pwd(void)
{
	char	*s;

	s = getcwd(0, 0);
	if (s == NULL)
		return (1);
	ft_putstr_fd(s, 1);
	ft_putchar_fd('\n', 1);
	free (s);
	return (0);
}
