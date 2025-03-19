/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:57:31 by leothoma          #+#    #+#             */
/*   Updated: 2025/03/19 16:57:55 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_2(t_list **head_a)
{
	if ((*head_a)->digit > (*head_a)->next->digit)
		sa(head_a);
}

void	sort_3(t_list **head_a)
{
	int a;
	int b;
	int c;

	a = (*head_a)->digit;
	b = (*head_a)->next->digit;
	c = (*head_a)->next->next->digit;
	if (a > b && b < c && a < c)
		sa(head_a);
	else if (a > b && b > c)
	{
		sa(head_a);
		rra(head_a);
	}
	else if (a > b && a > c)
		ra(head_a);
	else if (a < b && b > c && a < c)
	{
		sa(head_a);
		ra(head_a);
	}
	else if (a < b && a > c)
		rra(head_a);
}

void	sort_4(t_list **head_a, t_list **head_b)
{
	move_smallest_to_top(head_a);
	pb(head_a, head_b);
	sort_3(head_a);
	pa(head_a, head_b);
}

void	sort_5(t_list **head_a, t_list **head_b)
{
	move_smallest_to_top(head_a);
	pb(head_a, head_b);
	sort_4(head_a, head_b);
	pa(head_a, head_b);
}

void	get_stack_size(t_list **head_a, t_list **head_b)
{
	int	stack_size;

	stack_size = ft_lstsize(head_a);
	if (stack_size == 1)
		return ;
	else if (stack_size == 2)
		sort_2(head_a);
	else if (stack_size == 3)
		sort_3(head_a);
	else if (stack_size == 4)
		sort_4(head_a, head_b);
	else if (stack_size == 5)
		sort_5(head_a, head_b);
	else
		radix(head_a, head_b);
}
