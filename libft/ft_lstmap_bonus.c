/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:53:21 by leothoma          #+#    #+#             */
/*   Updated: 2024/11/23 22:53:21 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcheck(void *content, t_list **head, void (*del)(void *))
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
	{
		del(content);
		return (0);
	}
	node->content = content;
	node->next = NULL;
	ft_lstadd_back(head, node);
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	void	*ptr;

	head = 0;
	if (!lst)
		return (NULL);
	while (lst)
	{
		ptr = f(lst->content);
		if (!ft_lstcheck(ptr, &head, del) || !ptr)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (head);
}
