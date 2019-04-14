/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linedraw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <cmanfred@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:06:03 by cmanfred          #+#    #+#             */
/*   Updated: 2019/04/14 22:22:40 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_z_zero(t_map **map)
{
	int			x;
	int			y;
	t_vector	*v;

	y = -1;
	while (++y < (*map)->height)
	{
		x = -1;
		while (++x < (*map)->width)
		{
			v = ((*map)->vectors)[y * (*map)->width + x];
			v->z -= (*map)->min;
		}
	}
	(*map)->max -= (*map)->min;
	(*map)->min = 0;
}

/*
 ** Function, that calculates the color of every pixel
 */

static int	ft_bres_color(t_vector *pt1, t_line *line)
{
	// int		res;
	double	percent;
	int		col_r;
	int		col_g;
	int		col_b;

	if (line->dx > line->dy)
		percent = ((pt1->x - line->start.x) / (line->finish.x - line->start.x));
	else
		percent = ((pt1->y - line->start.y) / (line->finish.y - line->start.y));
	// col1 = (line->start.color >> 16) & 0xFF;
	// col2 = (line->finish.color >> 16) & 0xFF;
	col_r = ((line->start.color >> 16) & 0xFF) - (((line->start.color >> 16) & 0xFF - (line->finish.color >> 16) & 0xFF) * percent);
	col_g = ((line->start.color >> 8) & 0xFF) - (((line->start.color >> 8) & 0xFF - (line->finish.color >> 8) & 0xFF) * percent);
	col_b = ((line->start.color) & 0xFF) - (((line->start.color) & 0xFF - (line->finish.color) & 0xFF) * percent);
	return (col_r << 16 | col_g << 8 | col_b);
}

/*
 ** Function, that set a pixel, using the coordinates  of point 1, then changes
 ** point 1 coordinates according to bresenham algoritm
 */

static int	ft_make_bresenham(t_mlx *mlx, t_line *line,
		t_vector *pt1, t_vector *pt2)
{
	if (pt1->x < 0 || pt1->x >= WIN_WIDTH ||
			pt1->y < 0 || pt1->y >= WIN_HEIGHT
			|| pt2->x < 0 || pt2->x >= WIN_WIDTH
			|| pt2->y < 0 || pt2->y >= WIN_HEIGHT)
		return (1);
	image_set_pixel(mlx->image, (int)pt1->x, (int)pt1->y,
			ft_bres_color(pt1, line));
	if (line->fau > -(line->dx))
	{
		line->fau -= line->dy;
		pt1->x += line->sx;
	}
	if (line->fau < 0)
	{
		line->fau += line->dx;
		pt1->y += line->sy;
	}
	return (0);
}

/*
 ** Function, that calculate some constants for bresenham algorithm and then
 ** launches it
 */

static void	ft_drawline(t_mlx *mlx, t_vector pt1, t_vector pt2)
{
	t_line	line;

	pt1.x = (int)pt1.x;
	pt2.x = (int)pt2.x;
	pt1.y = (int)pt1.y;
	pt2.y = (int)pt2.y;
	line.start = pt1;
	line.finish = pt2;
	if (!(ft_cut_off(&pt1, &pt2)))
		return ;
	line.dx = (int)ft_module((int)(pt1.x) - (int)(pt2.x));
	line.dy = (int)ft_module((int)(pt1.y) - (int)(pt2.y));
	line.sx = (int)pt1.x < (int)pt2.x ? 1 : -1;
	line.sy = (int)pt1.y < (int)pt2.y ? 1 : -1;
	line.fau = (line.dx > line.dy ? line.dx : -line.dy) / 2.0f;
	while (!((int)(pt1.x) == (int)(pt2.x) && (int)(pt1.y) == (int)(pt2.y)))
		if (ft_make_bresenham(mlx, &line, &pt1, &pt2))
			break ;
}

/*
 ** Function, that renderes the image, projecting points with some variables of
 ** angle, scale, offset etc. and call ft_drawline wit these points
 */

void		ft_putimage(t_mlx *mlx)
{
	int			x;
	int			y;
	t_vector	v;
	t_map		*map;

	map = mlx->map;
	y = -1;
	ft_bzero(mlx->image->data, WIN_WIDTH * WIN_HEIGHT * mlx->image->bitspp);
	ft_minmax(map);
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			v = project_vector(vector_pos(map, x, y), mlx);
			if (x + 1 < map->width)
				ft_drawline(mlx, v,
						project_vector(vector_pos(map, x + 1, y), mlx));
			if (y + 1 < map->height)
				ft_drawline(mlx, v,
						project_vector(vector_pos(map, x, y + 1), mlx));
		}
	}
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->image->ptr, 0, 0);
}
