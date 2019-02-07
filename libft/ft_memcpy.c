/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:37:48 by cmanfred          #+#    #+#             */
/*   Updated: 2018/12/21 15:13:52 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	*sr;

	if (!dst && !src && n)
		return (NULL);
	res = (unsigned char *)dst;
	sr = (unsigned char *)src;
	i = -1;
	while (++i < n)
		*(res + i) = *(sr + i);
	return (dst);
}
