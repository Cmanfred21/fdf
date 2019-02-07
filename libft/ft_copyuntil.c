/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copyuntil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:19:40 by cmanfred          #+#    #+#             */
/*   Updated: 2018/12/24 17:12:46 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t		ft_copyuntil(char **dst, char *src, char c)
{
	size_t	i;
	char	*res;
	char	*tmp;

	tmp = *dst;
	i = -1;
	while (src[++i] != '\0')
		if ((unsigned char)src[i] == (unsigned char)c)
			break ;
	res = ft_strndup(src, i);
	if (!(*dst = ft_strjoin(*dst, res)))
	{
		free(res);
		return (0);
	}
	free(res);
	if (tmp)
		free(tmp);
	return (i);
}
