/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:23:35 by fharing           #+#    #+#             */
/*   Updated: 2021/11/17 09:52:59 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int	ft_quotes(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

void	ft_set_flag(int *c, int *flag, int value)
{
	(*c)++;
	if (*c % 2 == 0)
		*flag = 0;
	else
		*flag = value;
}

void	ft_init_values(int *i, int *x, int *flag, int *c)
{
	*i = 0;
	*x = 0;
	*flag = 0;
	*c = 0;
}

void	ft_set_values(char *re, char c, int *x)
{
	re[*x] = c;
	*x = *x + 1;
}

char	*ft_remove_quotes(char *s)
{
	char	*re;
	int		i;
	int		x;
	int		flag;
	int		c;

	if (!s)
		return (ft_calloc(1, 1));
	re = malloc(ft_strlen(s) + 1);
	ft_init_values(&i, &x, &flag, &c);
	while (s[i] != 0)
	{
		if (ft_quotes(s[i]) == 0 && flag == 0)
			flag = -1;
		if (s[i] == '\'' && flag != 2)
			ft_set_flag(&c, &flag, 1);
		else if (s[i] == '"' && flag != 1)
			ft_set_flag(&c, &flag, 2);
		else if (flag == 1 || flag == 2 || flag == -1)
			ft_set_values(re, s[i], &x);
		i++;
	}
	re[x] = 0;
	return (re);
}

// int	main(void)
// {
// 	char a[] = "echo 'te\"\"st' sadasdasd";
// 	char b[] = "This is a \"te\"st";
// 	char c[] = "echo \"te''st\"";
// 	char d[] = "ec\"h\"o \"as'da\"sd'a'";
// 	char s[] = "This is a 'te'st";
// 	char x[] = "Th""""""""is is the last test";
// 	char aa[] = "echo hell\"o''''''''''''''\"";
// 	char ab[] = "echo hell\"o'''''\"";
// 	char ac[] = "echo hell\"o''\"'''\"\"'";
// 	char ad[] = "\"e\"cho \"-e test\"";
// 	char *re = ft_remove_quotes(a);
// 	char *re2 = ft_remove_quotes(b);
// 	char *re3 = ft_remove_quotes(c);
// 	char *re4 = ft_remove_quotes(d);
// 	char *re5 = ft_remove_quotes(s);
// 	char *re6 = ft_remove_quotes(x);
// 	char *re7 = ft_remove_quotes(aa);
// 	char *re8 = ft_remove_quotes(ab);
// 	char *re9 = ft_remove_quotes(ac);
// 	char *re10 = ft_remove_quotes(ad);

// 	printf("\nSTRING before: %s\n", a);
// 	printf("STRING after: %s\n\n", re);

// 	printf("STRING before: %s\n", b);
// 	printf("STRING after: %s\n\n", re2);

// 	printf("STRING before: %s\n", c);
// 	printf("STRING after: %s\n\n", re3);

// 	printf("STRING before: %s\n", d);
// 	printf("STRING after: %s\n\n", re4);

// 	printf("STRING before: %s\n", s);
// 	printf("STRING after: %s\n\n", re5);

// 	printf("STRING before: %s\n", x);
// 	printf("STRING after: %s\n\n", re6);

// 	printf("STRING before: %s\n", aa);
// 	printf("STRING after: %s\n\n", re7);

// 	printf("STRING before: %s\n", ab);
// 	printf("STRING after: %s\n\n", re8);

// 	printf("STRING before: %s\n", ac);
// 	printf("STRING after: %s\n\n", re9);

// 	printf("STRING before: %s\n", ad);
// 	printf("STRING after: %s\n", re10);
// 	return (0);
// }
