/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:50:48 by fharing           #+#    #+#             */
/*   Updated: 2021/11/11 19:26:09 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	wordcount(const char *str, char c)
{
	size_t	i;
	size_t	count;
	int		flag;

	if (str == NULL)
		return (0);
	flag = 0;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i] != '\0')
		{
			flag = 0;
		}
		if (str[i] != c && str[i] != '\0' && !flag)
		{
			flag = 1;
			count++;
		}
		i++;
	}
	count++;
	return (count);
}

void	split_check_quotes(char c, int *f_quote, size_t *z, size_t *i)
{
	if (c == '\"' || c == '\'')
	{
		*f_quote *= -1;
		*z = *z + 1;
		*i = *i + 1;
	}
}

static	char	**ft_writestr(char const *s, size_t *x, char c, char **point)
{
	size_t	z;
	size_t	i;
	int		f_quote;

	i = 0;
	f_quote = -1;
	while (s[i] != '\0')
	{
		z = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		split_check_quotes(s[i], &f_quote, &z, &i);
		while ((s[i] != c || f_quote > 0) && s[i] != '\0')
		{
			if (s[i] == '\"' || s[i] == '\'')
				f_quote *= -1;
			z++;
			i++;
		}
		point[*x] = ft_substr(s, i - z, z);
		while (s[i] == c && s[i] != '\0')
			i++;
		*x = *x + 1;
	}
	return (point);
}

char	**ft_split_quote(char const *s, char c)
{
	size_t	x;
	char	**point;
	size_t	cnt;

	x = 0;
	cnt = 0;
	if (s == NULL)
		return (NULL);
	while (s[cnt] && (s[cnt] == c))
		cnt++;
	if (s[0] == '\0' || wordcount(s, c) < 1 || cnt >= ft_strlen(s))
	{
		point = malloc (sizeof(char *));
		point[0] = NULL;
		return (point);
	}
	point = (char **)(malloc((wordcount(s, c)) * sizeof(char *)));
	if (point == NULL || wordcount(s, c) == 0)
		return (point);
	point[x] = ft_writestr(s, &x, c, point)[x];
	point[x] = NULL;
	return (point);
}
