/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:12:17 by cmanfred          #+#    #+#             */
/*   Updated: 2018/12/20 14:48:49 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	chr;

	str = (char *)s;
	str -= 1;
	chr = c;
	while (*(++str) != chr)
	{
		if (*str == '\0')
			return (NULL);
	}
	return (str);
}
