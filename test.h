/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:36:53 by leothoma          #+#    #+#             */
/*   Updated: 2024/12/27 13:36:53 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H


typedef struct stack
{
	int	size;
	int	top;
	int	content;
	struct	stack *next;
} s_list;

void	sa(s_list **head);
void	sb(s_list **head);
void	ss(s_list **head_a, s_list **head_b);
void	pa(s_list **head_a, s_list **head_b);


s_list	*ft_new(int content);
void	ft_lstaddfront(s_list **lst, s_list *node);
void	ft_lstaddback(s_list **lst, s_list *node);
s_list	*ft_init_list(char **av);
s_list	*ft_init_list_b(char **av);


#endif
