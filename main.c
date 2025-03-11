/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:03:58 by leothoma          #+#    #+#             */
/*   Updated: 2025/03/05 14:03:59 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	count;
	int	neg;

	i = 0;
	res = 0;
	count = 0;
	neg = 0;
	while (((str[i] >= 9 && str[i] <= 13) || (str[i]) == 32))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		count++;
		if (str[i] == '-')
			neg++;
		if (count > 1)
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + str[i++] - 48;
	if (neg % 2 == 1)
		res *= -1;
	return (res);
}

int	checker(int num)
{
	(void)num;	
	return (1);
}

t_list	*init_stack(char **av, int start)
{
	t_list *stack;
	t_list *temp;
	int	i;
	int	count;
	
	i = start;
	count = 0;
	stack = 0;
	while (av[i])
	{
		temp = ft_new(ft_atoi(av[i]));
		if (!temp)
			return (NULL);
		temp->index = i;
		if (count == 0)
			stack = temp;
		else
			ft_lstaddback(&stack, temp);
		i++;
		count++;
	}
	return (stack);
}

char	**ft_parse(char *str)
{
	char	**res;

	res = 0;
	return (res = ft_split(str, ' '));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	no_doubles(char *str)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (str[i])
	{
		y = 0;
		while (str[y])
		{
			y++;
			if (str[i] == str[y])
				return (1);
		}
 		i++;
	}
	return (0);
}

int	check_parsing(char **av)
{
	int	i;
	int	y;
	int	j;
	int	count;
	char	buffer[10000];

	i = 1;
	y = 0;
	j = 0;
	while (av[i])
	{
		while (av[i][y])
		{
			if (!is_digit(av[i][y]))
				return (1);
			buffer[j] = av[i][y];
			y++;
			j++;
		}
		i++;
		y = 0;
	}
	count = no_doubles(buffer);
	if (count == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{	
	t_list *stack_a;
	t_list *stack_b;
	char	**args;
	int	check;

	check = 0;
	stack_a = 0;
	stack_b = 0;
	check = check_parsing(av);
	if (ac == 1)
		return (0);
	if (ac > 1 && check == 0)
	{
		if (ac == 2)
		{
			args = ft_parse(av[1]);
			stack_a = init_stack(args, 0);
		}
		else
			stack_a = init_stack(av, 1);
		radix(&stack_a, &stack_b);
	}
	else
		write(1, "error", 5);
	return (0);
}
