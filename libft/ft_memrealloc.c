/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:20:58 by cmanfred          #+#    #+#             */
/*   Updated: 2018/12/23 13:43:47 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memrealloc(void *src, size_t new_size, size_t old_size)
{
	void	*res;

	if (!new_size || !(res = ft_memalloc(new_size)))
		return (NULL);
	if (!src)
		return (ft_memalloc(new_size));
	ft_memmove(res, (const void *)src, old_size);
	free(src);
	return (res);
}
