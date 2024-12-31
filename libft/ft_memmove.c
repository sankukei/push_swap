/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:07:05 by leothoma          #+#    #+#             */
/*   Updated: 2024/11/06 23:07:05 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*t_dest;
	unsigned const char	*t_src;

	t_dest = dest;
	t_src = src;
	if (t_dest == t_src || n == 0)
		return (dest);
	if (t_dest < t_src)
	{
		while (n--)
			*t_dest++ = *t_src++;
	}
	else
	{
		t_dest += n;
		t_src += n;
		while (n--)
			*--t_dest = *--t_src;
	}
	return (dest);
}
