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

void	init_vars_2(t_vars *vars, t_list **head_a, t_list *temp)
{
	temp = *head_a;
	vars->min_value = temp->digit;
	vars->min_index = 0;
	vars->j = 0;
	vars->size = ft_lstsize(head_a);
}

void	move_smallest(t_list **head_a, t_vars *vars)
{
	t_list		*temp;

	temp = 0;
	init_vars_2(vars, head_a, temp);
	temp = *head_a;
	vars->min_value = temp->digit;
	while (temp)
	{
		if (temp->digit < vars->min_value)
		{
			vars->min_value = temp->digit;
			vars->min_index = vars->j;
		}
		temp = temp->next;
		vars->j++;
	}
	while (vars->min_index--)
		ra(head_a);
}
