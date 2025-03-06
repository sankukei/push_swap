/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:38:07 by leothoma          #+#    #+#             */
/*   Updated: 2025/03/06 14:38:08 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pa(t_list **head_a, t_list **head_b)
{
	push(head_a, head_b);
	write(1,"pa", 1);
}

void	pb(t_list **head_a, t_list ** head_b)
{
	push(head_b, head_a);
	write(1, "pb", 2);
}

void	rotate(t_list **head)
{
	t_list	*temp1;
	t_list	*temp2;
	t_list	*current;
	
	temp1 = *head;
	temp2 = (*head)->next;
	current = *head;
	while (current && current->next)
		current = current->next;
	current->next = temp1;
	temp1->next = NULL;
	*head = temp2;
}

void	ra(t_list **head)
{
	rotate(head);
	write(1, "ra", 2);
}

void	rb(t_list **head)
{
	rotate(head);
	write(1, "rb", 2);
}
