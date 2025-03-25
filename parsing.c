/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:58:59 by leothoma          #+#    #+#             */
/*   Updated: 2025/03/24 12:59:00 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_parsing(char **av)
{
	int		i;
	int		y;
	int		count;
	long	temp;

	i = 1;
	y = 0;
	while (av[i])
	{
		while (av[i][y])
		{
			if (!is_digit(av[i][y]))
				return (1);
			temp = ft_atoi(av[i]);
			if ((temp > 2147483647) || (temp < -2147483648))
				return (1);
			y++;
		}
		i++;
		y = 0;
	}
	count = no_doubles(av);
	if (count == 1)
		return (1);
	return (0);
}

int	is_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	no_doubles(char **av)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			check = ft_memcmp(av[i], av[j], ft_max(ft_strlen(av[j]), ft_strlen(av[i])));
			if (check == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_parse(char *str)
{
	char	**res;

	res = ft_split(str, ' ');
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
