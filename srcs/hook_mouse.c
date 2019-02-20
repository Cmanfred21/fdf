/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:34:57 by cmanfred          #+#    #+#             */
/*   Updated: 2019/02/20 18:07:26 by cmanfred         ###   ########.fr       */
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
	but = 0;
	mlx->mouse->down = 0;
	return (0);
}

int		ft_mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->mouse->prevx == 0)
		mlx->mouse->prevx = x;
	if (mlx->mouse->prevy == 0)
		mlx->mouse->prevy = y;
	mlx->mouse->prevx = mlx->mouse->x;
	mlx->mouse->prevy= mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if ((mlx->mouse->down & (1 << 2)) && (mlx->mouse->down & (1 << 1)))
		mlx->cam->scale += ((x - mlx->mouse->prevx) / 2000.0f) * (mlx->cam->scale * 2.1f);
	else if (mlx->mouse->down & (1 << 2))
	{
		mlx->cam->offsetx += x - mlx->mouse->prevx;
		mlx->cam->offsety += y - mlx->mouse->prevy;
	}
	else if (mlx->mouse->down & (1 << 1))
	{
		mlx->cam->y += (x - mlx->mouse->prevx) / 200.0f;
		mlx->cam->x -= (y - mlx->mouse->prevy) / 200.0f;
	}
	else if ((mlx->mouse->down & (1 << 3)))
		mlx->cam->zscale += (x - mlx->mouse->prevx) / 200.0f;
	ft_putimage(mlx);
	return (0);
}
