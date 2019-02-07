/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:34:52 by cmanfred          #+#    #+#             */
/*   Updated: 2018/11/25 17:53:34 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	n = -1;
	i = 0;
	if (ft_strlen(s1) == 0)
		return (NULL);
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (s1[i] != '\0' && ++n < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] != '\0' && n + j < len)
			j++;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
