/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:15:57 by leothoma          #+#    #+#             */
/*   Updated: 2024/12/28 18:15:57 by leothoma         ###   ########.fr       */
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
//	s_list	*tmp;
	ft_lstaddfront(head_a, *head_b);
//	tmp = (*head_b)->next;

	//free(*head_b);
//	(*head_b)->next = 0;
//	(*head_b) = 0;
//	head_b = &tmp;
	ft_printf("pa\n");
}
