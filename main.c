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

int	is_sorted(t_list **head_a)
{
	t_list	*current;

	current = *head_a;
	while (current && current->next)
	{
		if (current->digit > current->next->digit)
			return (0);
		current = current->next;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int	i;
	long	res;
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

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

t_list	*init_stack(char **av, int start)
{
	t_list	*stack;
	t_list	*temp;
	int		i;
	int		count;

	i = start;
	count = 0;
	stack = 0;
	while (av[i])
	{
		temp = ft_new(ft_atoi(av[i]));
		if (!temp)
		{
			ft_lstclear(&stack, del);
			return (NULL);
		}
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

int	is_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '+' || c == '-')
		return (1);
	return (0);
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
			check = ft_memcmp(av[i], av[j], ft_strlen(av[i]));
			if (check == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_parsing(char **av)
{
	int	i;
	int	y;
	int	count;
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

int	main(int ac, char **av)
{	
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		check;

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
		if (!(is_sorted(&stack_a)))
		{
			get_stack_size(&stack_a, &stack_b);
			ft_lstclear(&stack_a, del);
		}
	}
	else
		write(1, "error", 5);
	return (0);
}
