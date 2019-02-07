/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:58:26 by cmanfred          #+#    #+#             */
/*   Updated: 2018/12/20 16:16:20 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*res;
	t_list	*tmp;

	if (!alst || !del)
		return ;
	res = *alst;
	while (res != NULL)
	{
		tmp = res->next;
		del(res, res->content_size);
		res = tmp;
	}
	*alst = NULL;
}
