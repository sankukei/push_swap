/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:15:57 by leothoma          #+#    #+#             */
/*   Updated: 2025/01/06 19:11:15 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "libft/libft.h"

void	sa(s_list **head)
{
	s_list	*tmp1;
	s_list	*tmp2;

	if (!head)
		return ;
	tmp1 = *head;
	tmp2 = (*head)->next; 
	tmp1->next = tmp2->next;
	(*head) = tmp2;
	(*head)->next = tmp1;
	ft_printf("sa\n");
}

void	sb(s_list **head)
{
	s_list	*tmp1;
	s_list	*tmp2;

	if (!head)
		return ;
	tmp1 = *head;
	tmp2 = (*head)->next; 
	tmp1->next = tmp2->next;
	(*head) = tmp2;
	(*head)->next = tmp1;
	ft_printf("sb\n");
}

void	ss(s_list **head_a, s_list **head_b)
{
	sa(head_a);
	sb(head_b);
	ft_printf("ss\n");
}

void	pa(s_list **head_a, s_list **head_b)
{
	s_list	*tmp;

	tmp = (*head_a)->next;
	(*head_a)->next = *head_b;
	head_b = &*head_a;
	head_a = &tmp;

	ft_printf("pa\n");
}
