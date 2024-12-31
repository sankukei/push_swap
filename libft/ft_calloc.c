/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:16:49 by leothoma          #+#    #+#             */
/*   Updated: 2024/11/13 01:16:49 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*res;
	unsigned char	*tmp;
	unsigned long	i;

	res = 0;
	i = 0;
	if (nmemb == 0 || size == 0)
		return (res = malloc(0));
	if (!(nmemb > ((size_t) - 1 / size)))
		res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	tmp = res;
	while (i++ < nmemb * size)
		*tmp++ = 0;
	return (res);
}
