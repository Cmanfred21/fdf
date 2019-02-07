/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:24:20 by cmanfred          #+#    #+#             */
/*   Updated: 2018/12/05 14:03:42 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = -1;
	while (i + (++j) + 1 < n && s2[j] != '\0')
		s1[i + j] = s2[j];
	if (i < n)
		s1[i + j] = '\0';
	if (n <= i)
		return (n + ft_strlen(s2));
	else
		return (i + ft_strlen(s2));
}
