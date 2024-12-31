/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:09:21 by leothoma          #+#    #+#             */
/*   Updated: 2024/11/13 01:09:21 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lsrc;
	size_t	ldest;
	size_t	x;

	i = 0;
	x = 0;
	lsrc = ft_strlen(src);
	ldest = ft_strlen(dest);
	while (dest[x])
		x++;
	while (src[i] && (i + x + 1) < size)
	{
		dest[x + i] = src[i];
		i++;
	}
	if (i < size)
		dest[x + i] = '\0';
	if (size <= ldest)
		return (lsrc + size);
	else
		return (lsrc + ldest);
}
