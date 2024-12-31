/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leothoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:39:27 by leothoma          #+#    #+#             */
/*   Updated: 2024/11/12 18:39:27 by leothoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		len;

	len = ft_strlen(src);
	i = 0;
	while (*src && i + 1 < size)
	{
		*dst++ = *src++;
		i++;
	}
	if (size != 0)
		*dst = '\0';
	return (len);
}
/*
int main(void)
{
	#include <stdio.h>
	char	res[10000];
	char	src[] = "xdddd les amis";
	size_t	len1;
	size_t	len2;


 	len1 = ft_strlcpy(res, src, 1);
 	len2 = strlcpy(res, src, 1);

	printf("%ld\n", len1);
	printf("%ld", len2);

}*/
