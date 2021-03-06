/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:33:15 by cmanfred          #+#    #+#             */
/*   Updated: 2018/12/20 14:51:20 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	if ((c <= '9' && c >= '0') || (c <= 'Z' && c >= 'A') ||
		(c <= 'z' && c >= 'a'))
		return (1);
	return (0);
}
