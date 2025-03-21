/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:04:58 by leothoma          #+#    #+#             */
/*   Updated: 2025/03/05 14:04:59 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int		index;
	int		digit;
	struct s_list	*next;
}	t_list;

typedef struct s_vars
{
	int	i;
	int	y;
	int	max_digit;
	int	max_bits;
	int	ac;
	int	num;
}	t_vars;

long		ft_atoi(const char *str);
int		ft_lstsize(t_list **lst);

t_list	*ft_new(int digit);

void	sa(t_list **head);
void	ft_lstaddfront(t_list **lst, t_list *new);
void	ft_lstaddback(t_list **lst, t_list *new);
void	pa(t_list **head_a, t_list **head_b);
void	pb(t_list **head_a, t_list **head_b);
void	ra(t_list **head);
void	rra(t_list **head);
void	rotate(t_list **head);
void	reverse_rotate(t_list **head);
void	radix(t_list **head_a, t_list **head_b);
void	push(t_list **receiving_stack, t_list **departure_stack);
void	sort_2(t_list **head_a);
void	move_smallest(t_list **head_a);
void	get_stack_size(t_list **head_a, t_list **head_b);
void	ft_lstclear(t_list **lst, void (*del)(int *));
void	del(int *ptr);
char	**ft_split(char const *s, char c);

#endif
