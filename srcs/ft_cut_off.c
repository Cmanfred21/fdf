/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_off.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:21:15 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/15 19:47:28 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_reason(t_vector *pt)
{
	if (pt->y >= WIN_HEIGHT)
		return (1);
	if (pt->y < 0)
		return (2);
	if (pt->x >= WIN_WIDTH)
		return (3);
	if (tp->x < 0)
		return (4);
	return (0);
}

static void	ft_minus_reason(t_vector *corr, t_vector *pt1, t_vector *pt2, int res)
{
	if (res == 1)
	{
		corr->x = pt1->x + (pt2->x - pt1->x) * (WIN_HEIGHT - pt1->y) / (pt2->y - pt1->y);
		corr->y = WIN_HEIGHT - 1;
	}
	else if (res == 2)
	{
		corr->x = pt1->x + (pt2->x - pt1->x) * (0 - pt1->y) / (pt2->y - pt1->y);
		corr->y = 0;
	}
	else if (res == 3)
	{
		corr->x = WIN_WIDTH - 1;
		corr->y = pt1->y + (pt2->y - pt1->y) * (WIN_WIDTH - pt1->x) / (pt2->x - pt1->x);
	}
	else if (res == 4)
	{
		corr->x = 0;
		corr->y = pt1->y + (pt2->y - pt1->y) * (0 - pt1->x) / (pt2->x - pt1->x);
	}
}

void		ft_cut_off(t_vector *pt1, t_vector *pt2)
{
	t_vector	corr;
	int			reason1;
	int			reason2;
	int			res;

	reason1 = ft_reason(pt1);
	reason2 = ft_reason(pt2);
	while (reason1 || reason2)
	{
		res = reason1 ? reason1 : reason2;
		ft_minus_reason(&v, pt1, pt2, res);
		if (res == reason1)
		{
			pt1->x = corr.x;
			pt1->y = corr.y;
			r1 = ft_reason(pt1);
		}
		else if (res == reason2)
		{
			pt2->x = corr.x;
			pt2->y = corr.y;
			r2 = ft_reason(pt2);
		}
	}
}
