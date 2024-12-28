/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:15:06 by leothoma          #+#    #+#             */
/*   Updated: 2024/12/27 10:15:06 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "libft/libft.h"

s_list	*ft_new(void *content)
{
	s_list *stack;

	stack = malloc(sizeof(s_list));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->next = NULL;
	return (stack);
}

void	ft_lstaddfront(s_list **lst, s_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstaddback(s_list **lst, s_list *new)
{
	s_list	*ptr;

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

s_list	**ft_init_list(int ac, char **av)
{
	s_list	**list;
	s_list	*tmp;
	int	i;
	ac++;
	i = 1;
	list = malloc(sizeof(s_list) * (ac - 1));
	if (!list)
		return (NULL);
	while (av[i])
	{
		if (i == 1)
			*list = ft_new(av[i]);
		else
		{
			tmp = ft_new(av[i]);
			ft_lstaddback(list, tmp);
		}
		i++;
	}
	return (list);
}

int	main(int ac, char **av)
{
	int	i;
	s_list *stack_a = NULL;
//	s_list *stack_b;
//
	i = 1;
	if (ac > 1)
		stack_a = *ft_init_list(ac, av);
	else
		ft_printf("Error");
	while (stack_a)
	{
		ft_printf("%s", stack_a->content);
		stack_a = stack_a->next;

	}
	return (0);
}
