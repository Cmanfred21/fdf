/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:56:48 by cmanfred          #+#    #+#             */
/*   Updated: 2018/11/25 15:55:05 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = -1;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (++i < n)
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
	return (0);
}
