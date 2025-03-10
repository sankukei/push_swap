/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:37:52 by leothoma          #+#    #+#             */
/*   Updated: 2025/03/06 14:37:53 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rr(t_list **head_a, t_list **head_b)
{
	write(1, "rr", 2);
	rotate(head_a);
	rotate(head_b);
}

void	reverse_rotate(t_list **head)
{
	t_list	*current;
	t_list	*temp;
	t_list	*sec_last;

	temp = *head;
	current = *head;
	sec_last = NULL;
	while (current->next != NULL)
	{
		sec_last = current;
		current = current->next;
	}
	sec_last->next = NULL;
	current->next = temp;
	*head = current;
}

void	rra(t_list **head)
{
	write(1, "rra", 3);
	reverse_rotate(head);
}

void	rrb(t_list **head)
{
	write(1, "rrb", 3);
	reverse_rotate(head);
}

void	rrr(t_list **head_a, t_list **head_b)
{
	write(1, "rrr", 3);
	reverse_rotate(head_a);
	reverse_rotate(head_b);
}
