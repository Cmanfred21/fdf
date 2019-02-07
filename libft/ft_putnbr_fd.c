/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:26:05 by cmanfred          #+#    #+#             */
/*   Updated: 2018/11/26 13:20:03 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		tmp[10];

	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n == 0)
		ft_putchar_fd('0', fd);
	i = 0;
	while (n != 0)
	{
		tmp[i] = n % 10;
		n /= 10;
		if (tmp[i] < 0)
			tmp[i] *= -1;
		i++;
	}
	while (i-- > 0)
		ft_putchar_fd(tmp[i] + '0', fd);
}
