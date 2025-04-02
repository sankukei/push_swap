/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:46:58 by leothoma          #+#    #+#             */
/*   Updated: 2025/03/25 17:46:59 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	free_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
	return (1);
}

void	init_vars(t_vars *vars, t_list **stack_a, t_list **stack_b)
{
	vars->min_value = 0;
	vars->min_index = 0;
	vars->size = 0;
	vars->j = 0;
	vars->check = 0;
	vars->check1 = 0;
	*stack_a = 0;
	*stack_b = 0;
}
