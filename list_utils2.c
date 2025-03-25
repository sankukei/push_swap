/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:57:24 by leothoma          #+#    #+#             */
/*   Updated: 2025/03/24 12:57:25 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_lstsize(t_list **lst)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *lst;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}
