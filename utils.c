/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:48:04 by leothoma          #+#    #+#             */
/*   Updated: 2025/03/19 19:48:36 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_smallest_to_top(t_list **head_a)
{
	t_list		*temp;
	int			min_value;
	int			min_index;
	int			i;
	int			size;

	temp = *head_a;
	min_value = temp->digit;
	min_index = 0;
	i = 0;
	size = ft_lstsize(head_a);
	while (temp)
	{
		if (temp->digit < min_value)
		{
			min_value = temp->digit;
			min_index = i;
		}
		temp = temp->next;
		i++;
	}
	if (min_index <= size / 2)
	{
		while (min_index--)
			ra(head_a);
	}
	else
	{
		min_index = size - min_index;
		while (min_index--)
			rra(head_a);
	}
}
