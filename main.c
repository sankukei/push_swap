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
	int		i;
	long	res;
	int		count;
	int		neg;

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

int	ft_free(char **av)
{
	free(av);
	return(1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_vars	vars;
	char	**args;

	init_vars(&vars, &stack_a, &stack_b);
	vars.check = check_parsing(av);
	if (ac > 1)
	{
		args = ft_parse(av[1]);
		vars.check1 = check_parsing(args);
		if (ac == 2 && !vars.check1)
			stack_a = init_stack(args, 0);
		else if (ac > 2 && !vars.check)
			stack_a = init_stack(av, 1);
		else
			return (write(2, "error\n", 6), free_args(args));
		if (!(is_sorted(&stack_a)))
			get_stack_size(&stack_a, &stack_b, &vars);
		lst_clear(&stack_a, &stack_b);
		free_args(args);
	}
	if (vars.check == 1 || vars.check1 == 1)
		return (write(1, "error\n", 6));
	return (0);
}
