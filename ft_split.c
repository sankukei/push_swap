/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:52:25 by leothoma          #+#    #+#             */
/*   Updated: 2025/03/11 15:52:27 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	free_all(char **res, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(res[i]);
		i++;
	}
	free(res);
	res = NULL;
}

static int	is_charset(char str, char c)
{
	if (str == c)
		return (1);
	return (0);
}

static int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*custom_dup(char *str, char c, char **tmp, int y)
{
	int		i;
	int		l;
	char	*res;

	i = 0;
	l = 0;
	while (str[l] && (!(is_charset(str[l], c))))
		l++;
	res = malloc(l + 1);
	if (!res)
	{
		free_all(tmp, y);
		return (NULL);
	}
	i = 0;
	while (i < l)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int			y;
	char		**res;
	char const	*sinistre;

	res = malloc((count_words((char *)s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	y = 0;
	while (*s)
	{
		if (!(is_charset(*s, c)))
		{
			sinistre = s;
			while (*s && is_charset(*s, c) == 0)
				s++;
			res[y] = custom_dup((char *)sinistre, c, res, y);
			if (!res[y])
				return (NULL);
			y++;
		}
		else
			s++;
	}
	res[y] = NULL;
	return (res);
}
