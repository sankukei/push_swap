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

void	delete_negatives(t_list **head, int ac)
{
	t_list	*current;
	t_list	*ptr;
	int	i;

	current = *head;
	while (ac-- && current)
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

void	radix(t_list **head_a, t_list **head_b, int ac)
{
	int	i;
	int	y;
	int	max_digit;
	int	max_bits;
	t_list	*current;


	delete_negatives(head_a, ac);	
	max_digit = ac - 1;
	max_bits = 0;
	i = 0;
	y = 0;
	while ((max_digit >> max_bits) != 0)
		++max_bits;
	while (i++ < max_bits)
	{
		while (y++ < ac)
		{
			int num = (*head_a)->digit;
			if ((num >> i) & 1)
				ra(head_a);
			else
				pb(head_a, head_b);
		}
		current = *head_b;
		while (current && current->next)
		{
			pb(head_a, head_b);
			current = current->next;
		}
	}
}
