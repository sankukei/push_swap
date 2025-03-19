/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:38:14 by leothoma          #+#    #+#             */
/*   Updated: 2025/03/06 14:38:23 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	delete_negatives(t_list **head)
{
	t_list	*current;
	t_list	*ptr;
	int		i;

	current = *head;
	while (current)
	{
		ptr = *head;
		i = 0;
		while (current && ptr)
		{
			if (current->digit > ptr->digit)
				i++;
			ptr = ptr->next;
		}
		current->index = i;
		current = current->next;
	}
}

void	radix(t_list **head_a, t_list **head_b)
{
	t_vars	v;

	v.i = 0;
	v.y = 1;
	v.max_digit = ft_lstsize(head_a);
	v.max_bits = 1;
	v.ac = ft_lstsize(head_a);
	delete_negatives(head_a);
	while ((v.max_digit >> v.max_bits) != 0)
		v.max_bits++;
	while (v.i < v.max_bits)
	{
		v.y = 0;
		while (v.y++ < v.ac)
		{
			v.num = (*head_a)->index;
			if (((v.num >> v.i) & 1) == 1)
				ra(head_a);
			else
				pb(head_a, head_b);
		}
		while (*head_b)
			pa(head_a, head_b);
		v.i++;
	}
}
