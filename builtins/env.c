/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:51:49 by fharing           #+#    #+#             */
/*   Updated: 2021/11/09 10:39:19 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/builtins.h"

int	ft_env(t_list *env)
{
	t_list	*tmp;

	while (env != NULL)
	{
		tmp = env->next;
		ft_putstr_fd(env->string, 1);
		ft_putchar_fd('\n', 1);
		env = tmp;
	}
	return (0);
}
