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
	t_list	**ptr;

	ptr = (*head_a)->next;
	if ((*head_a)->digit > ptr->next)
		sa(head_a);
}

void	sort_3(t_list **head_a)
{

}

void	sort_4(t_list **head_a)
{

}

void	sort_5(t_list **head_a)
{

}

void	get_stack_size(t_list **head_a, t_list **head_b)
{
	int	stack_size;

	stack_size = ft_lstsize(head_a);
	if (stack_size == 1)
		return ;
		//
	else if (stack_size == 2)
		return ;
	else if (stack_size == 3)
		return ;
	else if (stack_size == 4)
		return ;
	else if (stack_size == 5)
		return ;
	else
		radix(head_a, head_b);
}
