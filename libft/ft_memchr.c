/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:46:31 by cmanfred          #+#    #+#             */
/*   Updated: 2018/11/29 18:03:30 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	ch;

	i = -1;
	res = (unsigned char *)s;
	ch = (unsigned char)c;
	while (++i < n)
	{
		if (res[i] == ch)
			return (res + i);
	}
	return (NULL);
}
