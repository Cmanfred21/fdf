/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_off.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <cmanfred@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:21:15 by cmanfred          #+#    #+#             */
/*   Updated: 2019/04/14 22:43:24 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_reason(t_vector *pt)
{
	int		res;

	res = 0;
	if (pt->y >= WIN_HEIGHT)
		res |= 1;
	if (pt->y < 0)
		res |= (1 << 1);
	if (pt->x >= WIN_WIDTH)
		res |= (1 << 2);
	if (pt->x < 0)
		res |= (1 << 3);
	return (res);
}

static void	ft_minus_reason(t_vector *corr, t_vector *pt1, t_vector *pt2, int r)
{
	if (r & 1)
	{
		corr->x = pt1->x + (pt2->x - pt1->x) *
			(WIN_HEIGHT - pt1->y) / (pt2->y - pt1->y);
		corr->y = WIN_HEIGHT - 1;
	}
	else if (r & (1 << 1))
	{
		corr->x = pt1->x + (pt2->x - pt1->x) * (0 - pt1->y) / (pt2->y - pt1->y);
		corr->y = 0;
	}
	else if (r & (1 << 2))
	{
		corr->x = WIN_WIDTH - 1;
		corr->y = pt1->y + (pt2->y - pt1->y) *
			(WIN_WIDTH - pt1->x) / (pt2->x - pt1->x);
	}
	else if (r & (1 << 3))
	{
		corr->x = 0;
		corr->y = pt1->y + (pt2->y - pt1->y) * (0 - pt1->x) / (pt2->x - pt1->x);
	}
}

int			ft_cut_off(t_vector *pt1, t_vector *pt2)
{
	t_vector	corr;
	int			reason1;
	int			reason2;
	int			res;

	reason1 = ft_reason(pt1);
	reason2 = ft_reason(pt2);
	while ((reason1 | reason2) && !(reason1 & reason2))
	{
		res = reason1 ? reason1 : reason2;
		ft_minus_reason(&corr, pt1, pt2, res);
		if (res == reason1)
		{
			pt1->x = corr.x;
			pt1->y = corr.y;
			reason1 = ft_reason(pt1);
		}
		else if (res == reason2)
		{
			pt2->x = corr.x;
			pt2->y = corr.y;
			reason2 = ft_reason(pt2);
		}
	}
	return (!(reason1 & reason2));
}
