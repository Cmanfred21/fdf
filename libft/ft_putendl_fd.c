/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:24:04 by cmanfred          #+#    #+#             */
/*   Updated: 2018/11/29 23:08:58 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;

	if (!s)
		return ;
	i = -1;
	while (s[++i] != '\0')
		ft_putchar_fd(s[i], fd);
	ft_putchar_fd('\n', fd);
}
