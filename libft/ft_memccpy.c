/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:37:48 by cmanfred          #+#    #+#             */
/*   Updated: 2018/12/21 18:35:36 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	*sr;
	unsigned char	ch;

	res = (unsigned char *)dst;
	sr = (unsigned char *)src;
	ch = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		*(res + i) = *(sr + i);
		if (*(sr + i) == ch)
			return (dst + i + 1);
	}
	return (NULL);
}
