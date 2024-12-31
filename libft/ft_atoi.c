/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <leothoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:26:33 by leothoma          #+#    #+#             */
/*   Updated: 2024/11/10 04:31:33 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	count;
	int	neg;

	i = 0;
	res = 0;
	count = 0;
	neg = 0;
	while (((str[i] >= 9 && str[i] <= 13) || (str[i]) == 32))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		count++;
		if (str[i] == '-')
			neg++;
		if (count > 1)
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + str[i++] - 48;
	if (neg % 2 == 1)
		res *= -1;
	return (res);
}
