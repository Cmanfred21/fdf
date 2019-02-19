/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:34:57 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/19 21:48:46 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_mouse_down(int but, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	mlx->mouse->down |= (1 << but);
	return (0);
}

int		ft_mouse_up(int but, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	mlx->mouse->down &= ~(1 << but);
	return (0);
}

int		ft_mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->mouse->x == 0)
		mlx->mouse->x = x;
	if (mlx->mouse->y == 0)
		mlx->mouse->y = y;
	mlx->mouse->prevx = mlx->mouse->x;
	mlx->mouse->prevy= mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->down & (1 << 2))
	{
		mlx->cam->offsetx += x - mlx->mouse->prevx;
		mlx->cam->offsety += y - mlx->mouse->prevy;
	}
	ft_putimage(mlx);
	return (0);
}
