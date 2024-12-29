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
	int	tmp;

	if (!head)
		return ;
	tmp = head->content;
	head->content = head->next->content;
	head->next->content = tmp;
	ft_printf("sa\n");
}

void	sb(s_list *head)
{
	int	tmp;

	if (!head)
		return ;
	tmp = head->content;
	head->content = head->next->content;
	head->next->content = tmp;
	ft_printf("sb\n");

}

void	ss(s_list *head_a, s_list *head_b)
{
	sa(head_a);
	sb(head_b);
	ft_printf("ss\n");
}

void	pa(s_list **head_a, s_list *head_b)
{
	ft_lstaddfront(head_a, head_b);	
	ft_printf("pa\n");
}
