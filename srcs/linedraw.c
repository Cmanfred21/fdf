/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linedraw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <cmanfred@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:06:03 by cmanfred          #+#    #+#             */
/*   Updated: 2019/04/10 20:21:54 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include "../includes/fdf.h"

/*
 ** Function, that calculates the color of every pixel
 */

static int	ft_bres_color(t_vector *pt1, t_line *line)
{
	int		res;
	double	percent;
	int		col1;
	int		col2;

	if (line->dx > line->dy)
		percent = ((pt1->x - line->start.x) / (line->finish.x - line->start.x));
	else
		percent = ((pt1->y - line->start.y) / (line->finish.y - line->start.y));
	col1 = (line->start.color >> 16) & 0xFF;
	col2 = (line->finish.color >> 16) & 0xFF;
	res = col1 - ((col1 - col2) * percent);
	return (res << 16 | res << 8 | 255);
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
	ft_cut_off(&pt1, &pt2);
	line.dx = (int)ft_module((int)(pt1.x) - (int)(pt2.x));
	line.dy = (int)ft_module((int)(pt1.y) - (int)(pt2.y));
	line.sx = (int)pt1.x < (int)pt2.x ? 1 : -1;
	line.sy = (int)pt1.y < (int)pt2.y ? 1 : -1;
	line.fau = (line.dx > line.dy ? line.dx : -line.dy) / 2.0f;
	while (!((int)(pt1.x) == (int)(pt2.x) && (int)(pt1.y) == (int)(pt2.y)))
		if (ft_make_bresenham(mlx, &line, &pt1, &pt2))
			break ;
}

void	*ft_start_pthread(void *data1)
{
	int			x;
	int			y;
	t_vector	v;
	int			max;
	t_mlx		*mlx;
	t_map		*map;
	t_pthrdata	*data;

	data = (t_pthrdata *) data1;
	x = -1;
	y = data->ymin - 1;
	max = data->ymax;
	mlx = data->mlx;
	map = mlx->map;
	while (++y < max)
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
	return (NULL);
}

/*
 ** Function, that renderes the image, projecting points with some variables of
 ** angle, scale, offset etc. and call ft_drawline wit these points
 */

void		ft_putimage(t_mlx *mlx)
{
	t_map		*map;
	t_pthrdata	*thread_data;
	pthread_t	*threads;
	int			i;
	int			cp;

	map = mlx->map;
	ft_minmax(map);
	cp = 4;
	ft_bzero(mlx->image->data, WIN_WIDTH * WIN_HEIGHT * mlx->image->bitspp);
	threads = (pthread_t *)ft_memalloc(sizeof(pthread_t) * cp);
	thread_data = (t_pthrdata *)ft_memalloc(sizeof(t_pthrdata) * cp);
	i = -1;
	while (++i < cp)
	{
		thread_data[i].mlx = mlx;
		thread_data[i].ymin = i * (map->height / cp);
		thread_data[i].ymax = thread_data[i].ymin + (map->height / cp);
		if (i == cp - 1)
			if (map->height / cp * cp != map->height)
				thread_data[i].ymax += map->height - map->height / cp * cp;
		pthread_create(&(threads[i]), NULL, ft_start_pthread, &thread_data[i]);
	}
	i = -1;
	while (++i < cp)
		pthread_join(threads[i], NULL);
	free(threads);
	free(thread_data);
	mlx_put_image_to_window(mlx->init, mlx->window, mlx->image->ptr, 0, 0);
}
