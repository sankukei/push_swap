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

t_list	*init_stack(char **av)
{
	t_list *stack;
	t_list *temp;
	int	i;
	
	i = 1;
	stack = 0;
	while (av[i])
	{
		temp = ft_new(ft_atoi(av[i]));
		temp->index = i;
		if (!temp)
			return (NULL);
		if (i == 1)
			stack = temp;
		else
			ft_lstaddback(&stack, temp);
		i++;
	}
	//free(temp);
	return (stack);
}

int	main(int ac, char **av)
{	
	t_list *stack_a;
	t_list *stack_b;

	stack_a = 0;
	stack_b = 0;
	if (ac > 1)
	{
		stack_a = init_stack(av);
		if (ac > 5)
		{
			radix(&stack_a, &stack_b, ac);
		}
		// stack_b = init_stack(av);
		// rra(&stack_a);
		printf("stack a\n");
		while (stack_a)
		{
			printf("%d\n", stack_a->digit);
			stack_a = stack_a->next;
		}
		printf("stack b\n");
		while (stack_b)
		{
			printf("%d\n", stack_b->digit);
			stack_b = stack_b->next;
		}
	}
	return (0);
}
