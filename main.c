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

s_list	*ft_new(int content)
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

s_list	*ft_init_list(char **av)
{
	s_list	*list;
	s_list	*tmp;
	int	i;
	int	val;

	list = 0;
	i = 1;
	while (av[i])
	{
		val = ft_atoi(av[i]);
		tmp = ft_new(val);
		if (!tmp)
			return (NULL);

		if (i == 1)
			list = tmp;
		else
			ft_lstaddback(&list, tmp);
		i++;
	}
	return (list);
}

s_list	*ft_init_list_b(int ac, char **av)
{
	s_list	*list;
	s_list	*tmp;
	int	i;
//	int	val;

	ac++;
	list = 0;
	i = 0;
	while (av[i])
	{
	//	val = ft_atoi(av[i]);
		tmp = ft_new(i);
		if (!tmp)
			return (NULL);
		if (i == 1)
			list = tmp;
		else
			ft_lstaddback(&list, tmp);
		i++;
	}
	return (list);
}

int	main(int ac, char **av)
{
	int	i;
	int	a = 1;
	s_list *stack_a;
	s_list *stack_b;
	stack_a = 0;
	i = 1;
	if (ac > 1)
	{
		stack_a = ft_init_list(av);
		stack_b = ft_init_list_b(ac, av);
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}

	pa(&stack_a, stack_b);
	//AFFICHAGE STACK_A ET B
	while (stack_a)
	{
		int tmp = stack_a->content;
		ft_printf("STACK A VALEUR [%d]: %d\n", a, tmp);
		stack_a = stack_a->next;
		a++;
	}
	ft_printf("\n");
	a = 1;
	while (stack_b)
	{
		int tmp = stack_b->content;
		ft_printf("STACK B VALEUR [%d]: %d\n", a, tmp);
		stack_b = stack_b->next;
		a++;
	}
	return (0);
}

