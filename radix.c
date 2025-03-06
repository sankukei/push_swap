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


void	bubble_list(t_list **head)
{
	int	sorted;
	t_list	*current;
	t_list	*test;

	sorted = 0;
	current = *head;
	while (sorted == 0)
	{
		sorted = 1;
		while (current && current->next)
		{
			if ((int)current->digit > (int)current->next->digit)
			{
				swap(head);
				sorted = 0;
			}
			current = current->next;
		}
	}
}

// void	delete_negatives(t_list **head)
// {
// 	t_list	*current;

// 	current = *head;
// 	while (current && current->next)
// 	{
		
// 	}
// }

// void	radix(t_list **head_a, t_list **head_b, int ac)
// {
		
// }
