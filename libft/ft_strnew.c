/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:44:18 by cmanfred          #+#    #+#             */
/*   Updated: 2018/12/20 14:36:06 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*res;

	if (!(size + 1))
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(res, '\0', size + 1);
	return (res);
}
