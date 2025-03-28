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

void	del(int *ptr)
{
	(void)ptr;
}

void	ft_lstclear(t_list **lst, void (*del)(int *))
{
	if (!*lst)
		return ;
	ft_lstclear(&(*lst)->next, del);
	del(&(*lst)->digit);
	free(*lst);
	*lst = 0;
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
