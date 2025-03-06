/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:43:17 by leothoma          #+#    #+#             */
/*   Updated: 2025/03/05 16:52:15 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(t_list **head)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!head)
	 	return ;
	tmp1 = *head;
	tmp2 = (*head)->next;
	tmp1->next = tmp2->next;
	(*head) = tmp2;
	(*head)->next = tmp1;
}

void	sa(t_list **head)
{
	swap(head);
	write(1, "sa\n", 3);
}

void	sb(t_list **head)
{
	swap(head);
	write(1, "sb\n", 3);
}

void	ss(t_list **head_a, t_list **head_b)
{
	swap(head_a);
	swap(head_b);
	write(1, "ss\n", 3);
}


void	push(t_list **receiving_stack, t_list **departure_stack)
{
	t_list *temp;
	
	temp = (*departure_stack)->next;
	
	(*departure_stack)->next = *receiving_stack;
	*receiving_stack = *departure_stack;
	*departure_stack = temp;	
}

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

void	rr(t_list **head_a, t_list **head_b)
{
	rotate(head_a);
	rotate(head_b);
	write(1, "rr", 2);
}

// void	rra(t_list **head)
// {
// 	t_list	*current;
// 	t_list	*temp;

// 	temp = *head;
// 	current = *head;
// 	while (current && current->next && current->next->next)
// 		current = current->next;
// }