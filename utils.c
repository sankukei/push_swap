/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:15:57 by leothoma          #+#    #+#             */
/*   Updated: 2024/12/28 18:15:57 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "libft/libft.h"

void	sa(s_list *head)
{
	s_list*	tmp;
	tmp = malloc(sizeof(s_list));
	if (!head || !tmp)
		return ;

	tmp = head;
	head = head->next;
	head->next = tmp;
	ft_printf("sa\n");
}
