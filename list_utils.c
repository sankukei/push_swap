/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:38:50 by leothoma          #+#    #+#             */
/*   Updated: 2025/03/06 14:38:51 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	lst_clear(t_list **lst1, t_list **lst2)
{
	t_list	*tmp;

	tmp = *lst1;
	while (*lst1)
	{
		tmp = (*lst1)->next;
		free(*lst1);
		*lst1 = tmp;
	}
	while (*lst2)
	{
		tmp = (*lst2)->next;
		free(*lst2);
		*lst2 = tmp;
	}
}

t_list	*ft_new(int digit)
{
	t_list	*stack;

	stack = malloc(sizeof(t_list));
	if (!stack)
	{
		return (NULL);
	}
	stack->digit = digit;
	stack->next = NULL;
	return (stack);
}

void	ft_lstaddfront(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstaddback(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	ptr = *lst;
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	if (*lst)
	{
		(*lst)->next = new;
		*lst = ptr;
	}
	else
		*lst = new;
}
