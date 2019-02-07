/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:21:06 by cmanfred          #+#    #+#             */
/*   Updated: 2018/12/21 18:27:52 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sr;

	if (!dst && !src && len)
		return (NULL);
	dest = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (dest < sr)
		while (len--)
			*dest++ = *sr++;
	else
	{
		dest += len;
		sr += len;
		while (len--)
			*(--dest) = *(--sr);
	}
	return (dst);
}
