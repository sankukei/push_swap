/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <leothoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:49:18 by leothoma          #+#    #+#             */
/*   Updated: 2024/11/10 04:32:29 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trim(char c, char const *set);

static int	m_size(char const *str, char const *set)
{
	int		i;
	size_t	count;
	int		len;

	count = 0;
	i = 0;
	len = ft_strlen(str) - 1;
	while (str[i] && is_trim(str[i], set))
	{
		count++;
		i++;
	}
	if (count == ft_strlen(str))
		return (count);
	while (is_trim(str[len], set))
	{
		count++;
		len--;
	}
	return (count);
}

static int	is_trim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		y;

	y = 0;
	res = malloc((ft_strlen(s1) - m_size(s1, set)) + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (is_trim(s1[i], set))
		i++;
	while (is_trim(s1[j], set))
		j--;
	while (i <= j)
		res[y++] = s1[i++];
	res[y] = '\0';
	return (res);
}
/*
int main (void)
{
#include <stdio.h>
	ft_strtrim("   xxx   xxx", " x");
	printf("%s", ft_strtrim("xxaaax//helloxlesamisxxxxx//xxx", "/xa"));
	ft_strtrim("xxxhelloxlesamisxxx", "x");
  	return (0);
}*/
